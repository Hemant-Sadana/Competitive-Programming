int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size(),ans = 0;
    stack<int> num,ind;
    vector<int> left(n,-1),right(n,n);
    num.push(A[0]);ind.push(0);
    for(int i=1;i<n;i++)
    {
        while(!num.empty() && A[i] <= num.top())
        {
            num.pop();ind.pop();
        }
        if(!num.empty())
        left[i] = ind.top();
        num.push(A[i]);ind.push(i);
    }
    while(!num.empty())
    {
        num.pop();ind.pop();
    }
    num.push(A[n-1]);ind.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!num.empty() && A[i] <= num.top())
        {
            num.pop();ind.pop();
        }
        if(!num.empty())
        right[i] = ind.top();
        num.push(A[i]);ind.push(i);
    }
    for(int i=0;i<n;i++)
    ans = max(ans,(right[i] -(left[i] + 1))*A[i]);
    return ans;
}

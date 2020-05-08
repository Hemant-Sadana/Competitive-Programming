int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    vector<long int> left(n,0),right(n,0);
    stack<long int> val,ind;
    val.push(A[0]);
    ind.push(0);
    for(int i=1;i<n;i++)
    {
        while(!val.empty() && A[i]>=val.top())
        {
            val.pop();ind.pop();
        }
        if(val.empty())
        left[i] = 0;
        else
        left[i] = ind.top();
        val.push(A[i]);
        ind.push(i);
    }
    while(!val.empty())
    {
        val.pop();ind.pop();
    }
    val.push(A[n-1]);
    ind.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!val.empty() && A[i]>=val.top())
        {
            val.pop();ind.pop();
        }
        if(val.empty())
        right[i] = 0;
        else
        right[i] = ind.top();
        val.push(A[i]);
        ind.push(i);
    }
    long int ans = 0;
    for(int i=1;i<n-1;i++)
    ans = max(ans,(left[i]*right[i]));
    return ans%1000000007;
}

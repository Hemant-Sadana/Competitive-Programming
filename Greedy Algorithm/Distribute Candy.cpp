int Solution::candy(vector<int> &A) {
    int n = A.size(),ans = 0;
    vector<int> temp(n,1);
    for(int i=1;i<n;i++)
    {
        if(A[i]>A[i-1])
        temp[i] = temp[i-1] + 1;
    }
    ans = temp[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]>A[i+1])
        temp[i] = max(temp[i+1]+1,temp[i]);
        ans += temp[i];
    }
    return ans;
}

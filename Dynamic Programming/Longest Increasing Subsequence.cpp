int Solution::lis(const vector<int> &A) {
    int n = A.size(),ans = 0;
    vector<int> inc(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(A[i]>A[j])
            inc[i] = max(inc[i],inc[j] + 1);
        }
        ans = max(ans,inc[i]);
    }
    return ans;
}

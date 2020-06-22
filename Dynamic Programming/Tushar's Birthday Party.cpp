int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int n = A.size(),cap = INT_MIN,ans = 0,m = B.size();
    for(int i=0;i<n;i++)
    cap = max(cap,A[i]);
    vector<vector<int> > dp(cap+1,vector<int> (m+1,0));
    for(int i=1;i<=cap;i++)
    dp[i][0] = 1000000;
    for(int i=1;i<=cap;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i-B[j-1]>=0)
            dp[i][j] = min(C[j-1] + dp[i-B[j-1]][j],dp[i][j-1]);
            else
            dp[i][j] = dp[i][j-1];
        }
    }
    for(int i=0;i<n;i++)
    ans += dp[A[i]][m];
    return ans;
}

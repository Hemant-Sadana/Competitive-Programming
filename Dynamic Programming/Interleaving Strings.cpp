int Solution::isInterleave(string A, string B, string C) {
    int y1 = A.size(),y2 = B.size(),y3 = C.size();
    if(y1+y2!=y3)
    return 0;
    vector<vector<bool> > dp(y1+1,vector<bool>(y2+1,false));
    dp[0][0] = true;
    for(int i=0;i<=y1;i++)
    {
        for(int j=0;j<=y2;j++)
        {
            if(i==0 && j==0)
            dp[i][j] = true;
            else if(i==0)
            dp[i][j] = dp[i][j-1] && B[j-1] == C[i+j-1];
            else if(j==0)
            dp[i][j] = dp[i-1][j] && A[i-1] == C[i+j-1];
            else
            dp[i][j] = dp[i-1][j] && A[i-1] == C[i+j-1] || dp[i][j-1] && B[j-1] == C[i+j-1];
        }
    }
    return dp[y1][y2];
}

int Solution::numDistinct(string A, string B) {
    int y1 = A.size(),y2 = B.size();
    vector<vector<int> > dp(y1+1,vector<int> (y2+1,0));
    for(int i=0;i<=y1;i++)
    dp[i][0] = 1;
    for(int i=1;i<=y1;i++)
    {
        for(int j=1;j<=y2;j++)
        {
            if(A[i-1] == B[j-1])
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    return dp[y1][y2];
}

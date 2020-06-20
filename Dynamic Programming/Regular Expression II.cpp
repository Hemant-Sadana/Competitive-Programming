int Solution::isMatch(const string A, const string B) {
    int y1 = A.size(),y2 = B.size();
    vector<vector<bool> > dp(y2+1,vector<bool> (y1+1,false));
    dp[0][0] = true;
    for(int i=1;i<=y2;i++)
    {
        for(int j=1;j<=y1;j++)
        {
            if(B[i-1] == A[j-1] || B[i-1] == '.')
            dp[i][j] = dp[i-1][j-1];
            if(B[i-1] == '*')
            dp[i][j] = dp[i-2][j] || ((B[i-2] == '.' || B[i-2] == A[j-1]) && (dp[i-2][j-1] || dp[i][j-1]));
        }
    }
    return dp[y2][y1];
}

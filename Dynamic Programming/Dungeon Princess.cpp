int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int  row = A.size(),col = A[0].size();
    vector<vector<int> > dp(row,vector<int> (col,0));
    if(A[row-1][col-1]<0)
    dp[row-1][col-1] = abs(A[row-1][col-1]);
    for(int i=row-1;i>=0;i--)
    {
        for(int j=col-1;j>=0;j--)
        {
            if(i == row-1 && j == col-1)
            continue;
            if(i == row-1)
            dp[i][j] = max(0,dp[i][j+1] - A[i][j]);
            else if(j == col-1)
            dp[i][j] = max(0,dp[i+1][j] - A[i][j]);
            else
            dp[i][j] = max(0,min(dp[i][j+1] - A[i][j],dp[i+1][j] - A[i][j]));
        }
    }
    return dp[0][0] + 1;
}

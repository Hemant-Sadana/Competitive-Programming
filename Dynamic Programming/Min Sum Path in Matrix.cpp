int Solution::minPathSum(vector<vector<int> > &A) {
    int row = A.size(),col = A[0].size();
    vector<vector<int> > dp(row,vector<int> (col,INT_MAX));
    dp[0][0] = A[0][0];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i+1<row)
            dp[i+1][j] = min(dp[i+1][j],dp[i][j] + A[i+1][j]);
            if(j+1<col)
            dp[i][j+1] = min(dp[i][j+1],dp[i][j] + A[i][j+1]);
        }
    }
    return dp[row-1][col-1];
}

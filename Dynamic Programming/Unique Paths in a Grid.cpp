int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int row = A.size(),col = A[0].size(),a,b;
    vector<vector<int> > dp(row,vector<int> (col,0));
    if(A[row-1][col-1] == 1 || A[0][0] == 1)
    return 0;
    dp[row-1][col-1] = 1;
    for(int i=row-1;i>=0;i--)
    {
        for(int j=col-1;j>=0;j--)
        {
            if(i==row-1 && j==col-1)
            continue;
            a = 0;b = 0;
            if(j+1<col && A[i][j+1] == 0)
            a = dp[i][j+1];
            if(i+1<row && A[i+1][j] == 0)
            b = dp[i+1][j];
            dp[i][j] = a+b;
        }
    }
    return dp[0][0];
}

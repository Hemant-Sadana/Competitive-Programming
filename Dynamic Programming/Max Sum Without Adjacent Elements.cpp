int Solution::adjacent(vector<vector<int> > &A) {
    int col = A[0].size();
    vector<int> dp(col+1,0);
    dp[1] = max(A[0][0],A[1][0]);
    for(int i=1;i<col;i++)
    {
        dp[i+1] = max(dp[i],dp[i-1] + max(A[0][i],A[1][i]));
    }
    return dp[col];
}

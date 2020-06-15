int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int row = A.size();
    vector<int> dp(row);
    for(int i=0;i<row;i++)
    dp[i] = A[row-1][i];
    for(int i=row-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            dp[j] = A[i][j] + min(dp[j],dp[j+1]);
        }
    }
    return dp[0];
}

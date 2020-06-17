int Solution::coinchange2(vector<int> &A, int B) {
    long int n = A.size(),a;
    vector<long int> dp(B+1,0);
    dp[0] = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=B;j++)
        {
            a = (j-A[i]>=0) ? dp[j-A[i]] : 0;
            dp[j] = (dp[j] + a)%1000007;
        }
    }
    return dp[B]%1000007;
}

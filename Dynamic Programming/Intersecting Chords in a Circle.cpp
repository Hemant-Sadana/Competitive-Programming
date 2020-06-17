int Solution::chordCnt(int A) {
    if(A == 0)
    return 1;
    int j,k;
    long int temp,ans;
    vector<long int> dp(A+1);
    dp[0] = 1;
    for(int i=1;i<=A;i++)
    {
        j = 0;k = i-1;ans = 0;
        while(j<=k)
        {
            temp = (dp[j] * dp[k])%1000000007;
            if(j != k)
            temp = (temp*2)%1000000007;
            ans = (ans + temp)%1000000007;
            j++;k--;
        }
        dp[i] = ans;
    }
    return dp[A];
}

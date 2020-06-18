int Solution::solve(const vector<int> &A) {
    int n = A.size(),x,ans = 2;
    if(n == 0 || n == 1)
    return n;
    map<int,int> hash;
    vector<vector<int> > dp(n,vector<int> (n)); 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            dp[i][j] = 2;
            x = 2*A[i] - A[j];
            if(hash.find(x) == hash.end())
            continue;
            dp[i][j] = max(dp[i][j],dp[hash[x]][i] + 1);
            ans = max(ans,dp[i][j]);
        }
        hash[A[i]] = i;
    }
    return ans;
}

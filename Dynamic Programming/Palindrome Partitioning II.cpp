bool ispalin(string t)
{
    int i=0,j = t.size()-1;
    while(i<j)
    {
        if(t[i]!=t[j])
        return false;
        i++;
        j--;
    }
    return true;
}
int Solution::minCut(string A) {
    int n = A.size();
    vector<int> dp(n+1,INT_MAX);
    dp[0] = -1;
    string t;
    for(int i=0;i<n;i++)
    {
        t = "";
        for(int j=i;j>=0;j--)
        {
            t = t+A[j];
            if(ispalin(t))
            dp[i+1] = min(dp[i+1],dp[j]+1);
        }
    }
    return dp[n];
    
}

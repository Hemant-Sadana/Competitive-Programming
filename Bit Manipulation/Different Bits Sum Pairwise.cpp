int Solution::cntBits(vector<int> &A) {
    int n = A.size();
    vector<int> ones(32,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<32;j++)
        {
            if(A[i]&(1<<j))
            ones[j]++;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<32;j++)
        {
            if(A[i] & (1<<j))
            ans = (ans + (n-ones[j]))%1000000007;
            else
            ans = (ans + ones[j])%1000000007;
        }
    }
    return ans;
}

int Solution::hammingDistance(const vector<int> &A) {
    int n = A.size(),c = 0;
    vector<int> ones(32,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<32;j++)
        {
            if(A[i] & (1<<j))
            ones[j]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<32;j++)
        {
            if(A[i] & (1<<j))
            c = (c + (n - ones[j]))%1000000007;
            else
            c = (c + ones[j])%1000000007;
        }
    }
    return c;
}

int Solution::singleNumber(const vector<int> &A) {
    int n = A.size(),ans = 0;
    vector<int> ones(32,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<32;j++)
        {
            if(A[i] & (1<<j))
            ones[j]++;
        }
    }
    for(int i=0;i<32;i++)
    {
        if(ones[i]%3)
        ans = ans + (1<<i);
    }
    return ans;
}

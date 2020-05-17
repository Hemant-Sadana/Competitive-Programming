int Solution::singleNumber(const vector<int> &A) {
    int n = A.size(),ans = 0,ones = 0;;
    for(int i=0;i<32;i++)
    {
        ones = 0;
        for(int j=0;j<n;j++)
        {
            if(A[j] & (1<<i))
            ones++;
        }
        if(ones%3)
        ans = ans + (1<<i);
    }
    return ans;
}

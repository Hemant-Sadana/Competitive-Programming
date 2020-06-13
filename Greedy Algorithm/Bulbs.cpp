int Solution::bulbs(vector<int> &A) {
    int n = A.size(),off = 0,ans = 0;
    for(int i=0;i<n;i++)
    {
        if(A[i] == off)
        {
            ans++;
            off = 1-off;
        }
    }
    return ans;
}

int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size(),sum=0,ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        ans = max(ans,sum);
        if(sum<0)
        sum = 0;
    }
    return ans;
}

int Solution::maxArea(vector<int> &A) {
    int n = A.size(),i = 0,j = n-1,ans = 0,m;
    while(i<j)
    {
        m = min(A[i],A[j]);
        ans = max(ans,m*(j-i));
        (m == A[i]) ? i++ : j--;
    }
    return ans;
}

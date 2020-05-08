int Solution::maximumGap(const vector<int> &A) {
    int n = A.size(),ans = 0;
    vector<int> B(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<n-1;i++)
    ans = max(ans,B[i+1]-B[i]);
    return ans;
}

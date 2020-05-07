int Solution::maximumGap(const vector<int> &A) {
    pair<int,int> temp[A.size()];
    int m = INT_MIN,ans = INT_MIN,n = A.size();
    for(int i=0;i<n;i++)
    {
        temp[i].first = A[i];
        temp[i].second = i;
    }
    sort(temp,temp+n);
    for(int i=n-1;i>=0;i--)
    {
        m = max(m,temp[i].second);
        ans = max(ans,m - temp[i].second);
    }
    return ans;
}

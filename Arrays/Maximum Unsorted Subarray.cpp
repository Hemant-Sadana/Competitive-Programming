vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size(),s,e,mn=INT_MAX,mx=INT_MIN,i;
    vector<int> ans;
    for(i=0;i<n-1;i++)
    {
        if(A[i]>A[i+1])
        break;
    }
    if(i==n-1)
    {
        ans.push_back(-1);
        return ans;
    }
    s = i+1;
    for(i=n-1;i>0;i--)
    {
        if(A[i]<A[i-1])
        break;
    }
    e = i-1;
    for(int i=s-1;i<=e+1;i++)
    {
        mn = min(mn,A[i]);
        mx = max(mx,A[i]);
    }
    for(i=s-1;i>=0;i--)
    {
        if(mn>=A[i])
        break;
    }
    ans.push_back(i+1);
    for(i=n-1;i>=e;i--)
    {
        if(mx>A[i])
        break;
    }
    ans.push_back(i);
    return ans;
}

int Solution::maxArr(vector<int> &A) {
    int n = A.size(),a=INT_MIN,b=INT_MAX,c=INT_MIN,d=INT_MAX;
    for(int i=0;i<n;i++)
    {
        a = max(a,A[i]+i);
        b = min(b,A[i]+i);
        c = max(c,A[i]-i);
        d = min(d,A[i]-i);
    }
    return max(a-b,c-d);
}

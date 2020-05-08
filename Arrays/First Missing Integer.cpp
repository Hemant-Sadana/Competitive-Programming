int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size(),f = 0;
    for(int i=0;i<n;i++)
    {
        if(A[i]<0)
        A[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        if(abs(A[i]) == n)
        f = 1;
        if(abs(A[i])<n && A[i]!=INT_MIN)
        {
            if(A[abs(A[i])]>0)
            A[abs(A[i])] = -A[abs(A[i])];
            if(A[abs(A[i])]==0)
            A[abs(A[i])] = INT_MIN;
        }
    }
    for(int i=1;i<n;i++)
    {
        if(A[i]>=0)
        return i;
    }
    if(f==1)
    return n+1;
    return n;
}

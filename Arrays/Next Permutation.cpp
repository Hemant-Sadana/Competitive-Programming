vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size(),s,i;
    for(i=n-1;i>0;i--)
    {
        if(A[i]>A[i-1])
        break;
    }
    if(i==0)
    {
        reverse(A.begin(),A.end());
        return A;
    }
    s = i-1;
    for(i=s+1;i<n;i++)
    {
        if(A[i]<=A[s])
        break;
    }
    swap(A[s],A[i-1]);
    reverse(A.begin()+s+1,A.end());
    return A;
}

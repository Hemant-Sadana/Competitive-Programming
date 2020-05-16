void Solution::sortColors(vector<int> &A) {
    int n = A.size(),j = -1;
    for(int i=0;i<n;i++)
    {
        if(A[i]==0)
        swap(A[i],A[++j]);
    }
    for(int i=j+1;i<n;i++)
    {
        if(A[i]==1)
        swap(A[i],A[++j]);
    }
}

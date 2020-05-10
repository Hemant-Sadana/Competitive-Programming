void Solution::arrange(vector<int> &A) {
    int n = A.size(),x,y;
    for(int i=0;i<n;i++)
    {
        x = A[i];
        y = A[x];
        if(x<i)
        y = A[x]/n;
        A[i] = n*A[i] + y;
    }
    for(int i=0;i<n;i++)
    A[i] = A[i]%n;
}

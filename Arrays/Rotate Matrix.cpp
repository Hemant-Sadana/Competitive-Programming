void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    int s = 0,e = n-1;
    while(s<e)
    {
        swap(A[s],A[e]);
        s++;
        e--;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(A[i][j],A[j][i]);
        }
    }
}

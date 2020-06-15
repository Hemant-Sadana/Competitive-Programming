bool mysort(int a,int b)
{
    return (a>b) ? true : false;
}
int Solution::solve(vector<vector<int> > &A) {
    if(A.size()==0)
    return 0;
    int row = A.size(),col = A[0].size(),ans = 0;
    for(int i=1;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(A[i][j] == 1)
            A[i][j] = A[i-1][j] + 1;
        }
    }
    for(int i=0;i<row;i++)
    {
        sort(A[i].begin(),A[i].end(),mysort);
        for(int j=0;j<col;j++)
        ans = max(ans,(A[i][j]*(j+1)));
    }
    return ans;
}

void generate(vector<vector<int> > &A,vector<vector<int> > &ans,int row,int col,int c)
{
    int n = A.size();
    int i=row,j=col;
    while(i<n && j>=0)
    {
        ans[c].push_back(A[i][j]);
        i++;
        j--;
    }
}
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int c = 0,n = A.size();
    vector<vector<int> > ans(2*n-1);
    for(int i=0;i<n;i++)
    generate(A,ans,0,i,c++);
    for(int i=1;i<n;i++)
    generate(A,ans,i,n-1,c++);
    return ans;
}

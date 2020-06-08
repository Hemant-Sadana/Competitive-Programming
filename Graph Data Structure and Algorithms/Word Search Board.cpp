bool dfs(int u,int v,vector<string> &A,string B,int k)
{
    if(k==B.size())
    return true;
    if(u<0 || u>=A.size() || v<0 || v>=A[0].size() || A[u][v]!=B[k])
    return false;
    if(dfs(u+1,v,A,B,k+1))
    return true;
    if(dfs(u,v+1,A,B,k+1))
    return true;
    if(dfs(u-1,v,A,B,k+1))
    return true;
    if(dfs(u,v-1,A,B,k+1))
    return true;
    return false;
}
int Solution::exist(vector<string> &A, string B) {
    int row = A.size(),col = A[0].size();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(A[i][j] == B[0])
            {
                if(dfs(i,j,A,B,0))
                return 1;
            }
        }
    }
    return 0;
}

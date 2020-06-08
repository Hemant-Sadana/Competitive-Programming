void bfs(int u,int v,vector<string> &A)
{
    queue<pair<int,int> > q;
    q.push(make_pair(u,v));
    int x[4] = {1,0,-1,0};
    int y[4] = {0,1,0,-1};
    pair<int,int> temp;
    A[u][v] = 'O';
    int i,j,m = A.size(),n = A[0].size();
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        i = temp.first;
        j = temp.second;
        for(int k=0;k<4;k++)
        {
            if(i+x[k]<0 || i+x[k]>=m || j+y[k]<0 || j+y[k]>=n || A[i+x[k]][j+y[k]] == 'O')
            continue;
            q.push(make_pair(i+x[k],j+y[k]));
            A[i+x[k]][j+y[k]] = 'O';
        }
    }
}
int Solution::black(vector<string> &A) {
    int m = A.size(),n = A[0].size(),c = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j] == 'X')
            {
                bfs(i,j,A);
                c++;
            }
        }
    }
    return c;
}

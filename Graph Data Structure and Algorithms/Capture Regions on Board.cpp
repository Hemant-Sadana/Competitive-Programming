void bfs(int u,int v,vector<vector<char> > &A)
{
    queue<pair<int,int> > q;
    pair<int,int> temp;
    q.push(make_pair(u,v));
    int x[4] = {1,0,-1,0};
    int y[4] = {0,1,0,-1};
    int row = A.size(),col = A[0].size();
    A[u][v] = 'Y';
    while(!q.empty())
    {
        temp  = q.front();
        q.pop();
        u = temp.first;
        v = temp.second;
        for(int i=0;i<4;i++)
        {
            if(u+x[i]<0 || u+x[i]>=row || v+y[i]<0 || v+y[i]>=col || A[u+x[i]][v+y[i]]!='O')
            continue;
            q.push(make_pair(u+x[i],v+y[i]));
            A[u+x[i]][v+y[i]] = 'Y';
        }
    }
}
void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int row = A.size(),col = A[0].size();
    for(int i=0;i<col;i++)
    {
        if(A[0][i] == 'O')
        bfs(0,i,A);
        if(A[row-1][i] == 'O')
        bfs(row-1,i,A);
    }
    for(int i=1;i<row;i++)
    {
        if(A[i][0] == 'O')
        bfs(i,0,A);
        if(A[i][col-1] == 'O')
        bfs(i,col-1,A);
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(A[i][j] == 'Y')
            A[i][j] = 'O';
            else if(A[i][j] == 'O')
            A[i][j] = 'X';
        }
    }
}

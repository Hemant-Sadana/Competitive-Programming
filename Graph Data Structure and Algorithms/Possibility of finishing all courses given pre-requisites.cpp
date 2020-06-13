bool dfs(int u,vector<vector<int> > &adj,vector<bool> &visited,vector<bool> &instack,int &f)
{
    instack[u] = true;
    visited[u] = true;
    for(int i=0;i<adj[u].size();i++)
    {
        if(instack[adj[u][i]] == 1)
        {
            f = 0;
            return false;
        }
        if(!visited[adj[u][i]] && f)
        dfs(adj[u][i],adj,visited,instack,f);
    }
    instack[u] = false;
    return f;
}
int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<vector<int> > adj(A);
    int n = B.size(),f = 1;
    for(int i=0;i<n;i++)
    {
        adj[C[i]-1].push_back(B[i]-1);
    }
    vector<bool> visited(A,false);
    vector<bool> instack(A,false);
    for(int i=0;i<A;i++)
    {
        if(!visited[i])
        {
            if(!dfs(i,adj,visited,instack,f))
            return 0;
        }
    }
    return 1;
}

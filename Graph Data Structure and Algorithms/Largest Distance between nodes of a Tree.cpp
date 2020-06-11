int find(vector<vector<int> > &adj,int u,int &ans)
{
    int n,n1 = 0,n2 = 0,sum = 0;
    for(int i=0;i<adj[u].size();i++)
    {
        n = find(adj,adj[u][i],ans);
        if(n>n1)
        {
            n2 = n1;
            n1 = n;
        }
        else if(n>n2)
        n2 = n;
    }
    sum = n1 + n2;
    ans = max(ans,max(sum,n1) + 1);
    return n1+1;
}
int Solution::solve(vector<int> &A) {
    int n = A.size(),ans = 0;
    vector<vector<int> > adj(n);
    for(int i=1;i<n;i++)
    {
        adj[A[i]].push_back(i);
    }
    find(adj,0,ans);
    return ans-1;
}

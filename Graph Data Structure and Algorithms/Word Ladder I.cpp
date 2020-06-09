int bfs(vector<vector<int> > &adj,int s,int d)
{
    int n = adj.size();
    queue<int> q;
    vector<int> dist(n,INT_MAX);
    dist[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        if(dist[s]>=dist[d])
        continue;
        for(int i=0;i<adj[s].size();i++)
        {
            if(dist[adj[s][i]] > dist[s] + 1)
            {
                q.push(adj[s][i]);
                dist[adj[s][i]] = dist[s] + 1;
            }
        }
    }
    return dist[d]+1;
}
int Solution::solve(string A, string B, vector<string> &C) {
    C.push_back(A);
    C.push_back(B);
    int n = C.size(),cnt = 0;
    vector<vector<int> > adj(n);
    string t1,t2;
    for(int i=0;i<n-1;i++)
    {
        t1 = C[i];
        for(int j = i+1;j<n;j++)
        {
            t2 = C[j];cnt = 0;
            for(int k=0;k<t1.size();k++)
            {
                if(t1[k]!=t2[k])
                cnt++;
                if(cnt == 2)
                break;
            }
            if(cnt == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    return bfs(adj,n-2,n-1);
}

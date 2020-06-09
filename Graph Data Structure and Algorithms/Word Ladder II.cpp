void insert(vector<string> &dict,vector<vector<string> > &ans,vector<string> temp,vector<vector<int> > parent,int s,int e)
{
    if(s==e)
    {
        temp.push_back(dict[e]);
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<parent[s].size();i++)
    {
        temp.push_back(dict[s]);
        insert(dict,ans,temp,parent,parent[s][i],e);
        temp.pop_back();
    }
}
void bfs(vector<vector<int> > &adj,vector<vector<int> > &parent,int s,int d)
{
    queue<int> q;
    q.push(s);
    int n = adj.size();
    vector<int> dist(n,INT_MAX);
    dist[s] = 0;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        for(int i=0;i<adj[s].size();i++)
        {
            if(dist[adj[s][i]] >= dist[s] + 1)
            {
                if(dist[adj[s][i]]>dist[s]+1)
                q.push(adj[s][i]);
                dist[adj[s][i]] = dist[s] + 1;
                parent[adj[s][i]].push_back(s);
            }
        }
    }
}
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string> > ans;
    vector<string> temp;
    if(start == end)
    {
        temp.push_back(start);
        ans.push_back(temp);
        return ans;
    }
    int s,e,ind = 0;
    map<string,int> hash;
    dict.push_back(start);
    dict.push_back(end);
    for(int i=0;i<dict.size();i++)
    hash[dict[i]] = i;
    dict.clear();
    for(auto k = hash.begin();k!=hash.end();k++)
    {
        if(k->first == start)
        s = ind;
        if(k->first == end)
        e = ind;
        ind++;
        dict.push_back(k->first);
    }
    string t1,t2;
    int cnt,n = dict.size();
    vector<vector<int> > adj(n);
    for(int i=0;i<n-1;i++)
    {
        t1 = dict[i];
        for(int j=i+1;j<n;j++)
        {
            t2 = dict[j];
            cnt = 0;
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
    vector<vector<int> > parent(n);
    bfs(adj,parent,e,s);
    insert(dict,ans,temp,parent,s,e);
    return ans;
}

bool mysort(vector<int> a,vector<int> b)
{
    if(a[2]<b[2])
    return true;
    return false;
}
int find(int u,vector<pair<int,int> > &subset)
{
    if(subset[u].first!=u)
    subset[u].first = find(subset[u].first,subset);
    return subset[u].first;
}
void unite(int u,int v,vector<pair<int,int> > &subset)
{
    if(subset[u].second>subset[v].second)
    {
        subset[v].first = u;
    }
    else if(subset[u].second<subset[v].second)
    {
        subset[u].first = v;
    }
    else
    {
        subset[u].first = v;
        subset[v].second++;
    }
}
int MST(int A,vector<vector<int> > B,vector<pair<int,int> > subset)
{
    int i = 0,u,v,wt = 0,e = 0,x,y;
    while(e<A-1)
    {
        u = B[i][0]-1;
        v = B[i][1]-1;
        x = find(u,subset);
        y = find(v,subset);
        if(x!=y)
        {
            unite(x,y,subset);
            wt += B[i][2];
            e++;
        }
        i++;
    }
    return wt;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(),B.end(),mysort);
    vector<pair<int,int> > subset(A);
    for(int i=0;i<A;i++)
    {
        subset[i].first = i;    /* Parent */
        subset[i].second = 0;   /* Rank */
    }
    return MST(A,B,subset);
}

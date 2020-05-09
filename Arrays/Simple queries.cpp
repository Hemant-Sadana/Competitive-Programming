bool mysort(pair<int,int> a,pair<int,int> b)
{
    return (a>=b)? true:false;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<int> left(n,-1);
    vector<int> right(n,n);
    stack<int> ind,val;
    val.push(A[0]);ind.push(0);
    for(int i=1;i<n;i++)
    {
        while(!val.empty() && A[i]>val.top())
        {
            val.pop();ind.pop();
        }
        if(!val.empty())
        left[i] = ind.top();
        val.push(A[i]);
        ind.push(i);
    }
    while(!val.empty())
    {
        val.pop();ind.pop();
    }
    val.push(A[n-1]);ind.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!val.empty() && A[i]>=val.top())
        {
            val.pop();ind.pop();
        }
        if(!val.empty())
        right[i] = ind.top();
        val.push(A[i]);
        ind.push(i);
    }
    vector<pair<int,int> > G;
    pair<int,int> temp;
    for(int i=0;i<n;i++)
    {
        temp.first = (A[i]);
        temp.second = (((right[i] - i)*(i-left[i])));
        G.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        int times = sqrt(G[i].first);
        long long int prod=1;
        for(int j=1;j<=times;j++)
        {
            if(G[i].first%j==0)
            {
                if(G[i].first/j!=j)
                prod = (prod*(G[i].first/j)*j)%long(1e9+7);
                else
                prod = (prod*j)%long(1e9+7);
            }
        }
        G[i].first = prod%long(1e9+7);
    }
    sort(G.begin(),G.end(),mysort);
    for(int i=n-2;i>=0;i--)
    G[i].second = G[i+1].second + G[i].second;
    vector<int> t;
    int x = B.size();
    for(int i=0;i<x;i++)
    {
        int start = 0,end = n-1;
        B[i] = G[0].second-B[i]+1;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(G[mid].second==B[i] || mid == n-1 || (G[mid].second>B[i] && G[mid+1].second<B[i]))
            {
                t.push_back(G[mid].first);
                break;
            }
            if(G[mid].second>B[i])
            start = mid+1;
            else
            end = mid-1;
        }
    }
    return t;
}

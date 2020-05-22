bool valid(int a,int b,int c,int d,int t1,int t2,int t3,int t4)
{
    if(a<t1)return true;
    if(a==t1 && b<t2)return true;
    if(a==t1 && b==t2 && c<t3)return true;
    if(a==t1 && b==t2 && c==t3 && d<t4)return true;
    return false;
}
vector<int> Solution::equal(vector<int> &A) {
    int n = A.size(),sum = 0,a,b,c,d;
    int t1 = INT_MAX,t2,t3,t4,f=0;
    t2 = t1;t3 = t1;t4 = t1;
    map<int,pair<int,int> > hash;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            sum = A[i] + A[j];
            if(hash.find(sum) == hash.end())
            hash[sum] = make_pair(i,j);
            else
            {
                a = hash[sum].first;b = hash[sum].second;c = i;d = j;
                if(a==c || b == c || b == d)
                continue;
                if(valid(a,b,c,d,t1,t2,t3,t4))
                {
                    t1 = a;t2 = b;t3 = c;t4 = d;
                    f  = 1;
                }
            }
        }
    }
    vector<int> ans;
    if(!f)
    return ans;
    ans.push_back(t1);ans.push_back(t2);ans.push_back(t3);ans.push_back(t4);
    return ans;
}

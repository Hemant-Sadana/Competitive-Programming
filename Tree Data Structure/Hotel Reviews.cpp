bool mysort(pair<int,int> a,pair<int,int> b)
{
    if(a.first>b.first || (a.first==b.first && a.second<b.second))
    return true;
    return false;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    map<string,int> hash;
    int n = A.size(),cnt = 0;
    vector<pair<int,int> > out;
    vector<int> ans;
    string temp="";
    for(int i=0;i<=n;i++)
    {
        if(i==n || A[i] == '_')
        {
            hash[temp] = 1;
            temp = "";
        }
        else
        temp += A[i];
    }
    n = B.size();
    for(int i=0;i<n;i++)
    {
        cnt = 0;temp = "";
        for(int j=0;j<=B[i].size();j++)
        {
            if(j==B[i].size() || B[i][j] == '_')
            {
                if(hash.find(temp)!=hash.end())
                cnt++;
                temp = "";
            }
            else
            temp += B[i][j];
        }
        out.push_back(make_pair(cnt,i));
    }
    sort(out.begin(),out.end(),mysort);
    for(int i=0;i<n;i++)
    ans.push_back(out[i].second);
    return ans;
}

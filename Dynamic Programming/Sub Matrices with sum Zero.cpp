int find(vector<int> &temp)
{
    int n = temp.size(),c = 0,sum = 0,zs = 0;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        sum = sum + temp[i];
        if(sum == 0)
        {
            zs++;
            c = c + zs;
            continue;
        }
        if(mp.find(sum)!=mp.end())
        c = c + mp[sum];
        mp[sum]++;
    }
    return c;
}
int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0)
    return 0;
    int row = A.size(),col = A[0].size(),ans = 0;
    vector<int> temp;
    for(int i=0;i<col;i++)
    {
        temp.clear();
        temp.resize(row,0);
        for(int j=i;j<col;j++)
        {
            for(int k=0;k<row;k++)
            temp[k] = temp[k] + A[k][j];
            ans = ans + find(temp);
        }
    }
    return ans;
}

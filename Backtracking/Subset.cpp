void generate(vector<int> &A,int index,int n,vector<int> temp,vector<vector<int> > &ans)
{
    if(index>=n)
    return;
    for(int i=index;i<n;i++)
    {
        temp.push_back(A[i]);
        ans.push_back(temp);
        generate(A,i+1,n,temp,ans);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    int n = A.size();
    sort(A.begin(),A.end());
    vector<vector<int> > ans;
    vector<int> temp;
    ans.push_back(temp);
    generate(A,0,n,temp,ans);
    return ans;
}

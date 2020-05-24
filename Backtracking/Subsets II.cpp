void generate(vector<int> &A,int index,vector<int> temp,vector<vector<int> > &ans)
{
    for(int i=index;i<A.size();i++)
    {
        temp.push_back(A[i]);
        ans.push_back(temp);
        generate(A,i+1,temp,ans);
        while(i<A.size()-1 && A[i] == A[i+1])
        i++;
        temp.pop_back();
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    int n = A.size();
    sort(A.begin(),A.end());
    vector<int> temp;
    vector<vector<int> > ans;
    ans.push_back(temp);
    generate(A,0,temp,ans);
    return ans;
}

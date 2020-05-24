void generate(vector<int> &A,int index,int n,vector<vector<int> > &ans)
{
    if(index == n)
    {
        ans.push_back(A);
        return;
    }
    for(int i=index;i<n;i++)
    {
        swap(A[i],A[index]);
        generate(A,index+1,n,ans);
        swap(A[i],A[index]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    int n = A.size();
    vector<vector<int> > ans;
    generate(A,0,n,ans);
    return ans;
}

void generate(int A,int B,int index,vector<int> temp,vector<vector<int> > &ans)
{
    if(temp.size()==B)
    {
        ans.push_back(temp);
        return;
    }
    for(int i=index;i<=A;i++)
    {
        temp.push_back(i);
        generate(A,B,i+1,temp,ans);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> > ans;
    if(B>A)
    return ans;
    vector<int> temp;
    generate(A,B,1,temp,ans);
    return ans;
}

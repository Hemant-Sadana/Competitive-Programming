void generate(vector<int> &A,int B,int index,vector<int> temp,vector<vector<int> > &ans,int sum)
{
    if(sum == B)
    {
        ans.push_back(temp);
        return;
    }
    if(sum>B)
    return;
    for(int i=index;i<A.size();i++)
    {
        temp.push_back(A[i]);
        sum = sum + A[i];
        generate(A,B,i,temp,ans,sum);
        temp.pop_back();
        sum = sum - A[i];
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int n = A.size();
    sort(A.begin(),A.end());
    vector<vector<int> > ans;
    vector<int> temp,unique;
    unique.push_back(A[0]);
    for(int i=1;i<n;i++)
    {
        if(A[i]!=A[i-1])
        unique.push_back(A[i]);
    }
    generate(unique,B,0,temp,ans,0);
    return ans;
}

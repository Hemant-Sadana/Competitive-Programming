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
        generate(A,B,i+1,temp,ans,sum);
        sum = sum - A[i];
        temp.pop_back();
        while(i<A.size()-1 && A[i+1]==A[i])
        {
            i++;
        }
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int n = A.size();
    sort(A.begin(),A.end());
    vector<int> temp;
    vector<vector<int> > ans;
    generate(A,B,0,temp,ans,0);
    return ans;
}

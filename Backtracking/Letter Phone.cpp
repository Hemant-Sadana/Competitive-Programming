void generate(vector<string> &B,int j,vector<string> &ans,int sz,string temp)
{
    if(j == sz)
    {
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<B[j].size();i++)
    {
        temp.push_back(B[j][i]);
        generate(B,j+1,ans,sz,temp);
        temp.pop_back();
    }
}
vector<string> Solution::letterCombinations(string A) {
    vector<string> temp = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n = A.size();
    vector<string> B;
    for(int i=0;i<n;i++)
    B.push_back(temp[A[i]-48]);
    vector<string> ans;
    generate(B,0,ans,B.size(),"");
    return ans;
}

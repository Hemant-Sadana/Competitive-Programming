bool palindrome(string t)
{
    int n = t.size();
    int i=0,j=n-1;
    while(i<j)
    {
        if(t[i]!=t[j])
        return false;
        i++;j--;
    }
    return true;
}
void generate(string A,int index,vector<string> temp,vector<vector<string> > &ans)
{
    if(index == A.size())
    {
        ans.push_back(temp);
        return;
    }
    string t = "";
    for(int i=index;i<A.size();i++)
    {
        t += A[i];
        temp.push_back(t);
        if(palindrome(t))
        generate(A,i+1,temp,ans);
        temp.pop_back();
    }
}
vector<vector<string> > Solution::partition(string A) {
    int n = A.size();
    vector<string> temp;
    vector<vector<string> > ans;
    generate(A,0,temp,ans);
    return ans;
}

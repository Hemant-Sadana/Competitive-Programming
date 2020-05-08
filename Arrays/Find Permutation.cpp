vector<int> Solution::findPerm(const string A, int B) {
    int n = A.size(),s = 1,e = B;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='I')
        {
            ans.push_back(s);
            s++;
        }
        else
        {
            ans.push_back(e);
            e--;
        }
    }
    ans.push_back(s);
    return ans;
}

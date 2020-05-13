string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size(),f = 0;
    string ans = "";
    char c;
    for(int i=0;i<A[0].size();i++)
    {
        c = A[0][i];
        for(int j=1;j<n;j++)
        {
            if(A[j].size()<i || A[j][i]!=c)
            {
                f = 1;
                break;
            }
        }
        if(f==1)
        break;
        ans = ans + c;
    }
    return ans;
}

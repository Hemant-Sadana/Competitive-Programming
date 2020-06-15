vector<int> Solution::solve(int A, vector<int> &B) {
    int n = B.size(),m = INT_MAX,bumps,j=0;
    for(int i=0;i<n;i++)
    m = min(m,B[i]);
    bumps = A/m;
    vector<int> ans;
    while(1)
    {
        if(bumps == 0)
        return ans;
        if((A-B[j]) >= (bumps-1)*m)
        {
            A = A-B[j];
            ans.push_back(j);
            bumps--;
        }
        else
        j++;
    }
}

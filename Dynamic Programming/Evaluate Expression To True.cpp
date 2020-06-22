int Solution::cnttrue(string A) {
    int n = A.size(),j,k,t,f;
    vector<int> opr,oprnd;
    for(int i=0;i<n;i++)
    {
        if(i%2)
        opr.push_back(A[i]);
        else
        oprnd.push_back(A[i]);
    }
    n = oprnd.size();
    vector<vector<int> > tr(n,vector<int> (n,0)),fal(n,vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        if(oprnd[i] == 'T')
        tr[i][i] = 1;
        else
        fal[i][i] = 1;
    }
    for(int l=1;l<n;l++)
    {
        for(int i=0;i<n-l;i++)
        {
            k = i;j = i+l;t = 0;f = 0;
            while(k<j)
            {
                if(opr[k] == '|')
                {
                    t = (t + tr[i][k]*fal[k+1][j] + fal[i][k]*tr[k+1][j] + tr[i][k]*tr[k+1][j])%1003;
                    f = (f + fal[i][k]*fal[k+1][j])%1003;
                }
                else if(opr[k] == '^')
                {
                    t = (t + tr[i][k]*fal[k+1][j] + fal[i][k]*tr[k+1][j])%1003;
                    f = (f + tr[i][k]*tr[k+1][j] + fal[i][k]*fal[k+1][j])%1003;
                }
                else
                {
                    t = (t + tr[i][k]*tr[k+1][j])%1003;
                    f = (f + tr[i][k]*fal[k+1][j] + fal[i][k]*tr[k+1][j] + fal[i][k]*fal[k+1][j])%1003;
                }
                k++;
            }
            tr[i][j] = t;
            fal[i][j] = f;
        }
    }
    return tr[0][n-1];
}

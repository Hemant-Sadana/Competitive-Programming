vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int row = B.size(),col = B[0].size(),temp;
    vector<vector<int> > ans(B.begin(),B.end());
    int x[4] = {1,0,-1,0};
    int y[4] = {0,1,0,-1};
    for(int l=0;l<A;l++)
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                temp = INT_MIN;
                for(int k=0;k<4;k++)
                {
                    if(i+x[k]<0 || i+x[k]>=row || j+y[k]<0 || j+y[k]>=col)
                    continue;
                    temp = max(ans[i][j],max(temp,B[i+x[k]][j+y[k]]));
                }
                ans[i][j] = temp;
            }
        }
        B = ans;
    }
    return B;
}

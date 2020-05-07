vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > ans(A,vector<int> (A));
    int count = 1,j=0;
    int times = ceil(A/2.0);
    while(j<times)
    {
        for(int i=j;i<A-j;i++)
        ans[j][i] = count++;

        for(int i=j+1;i<A-j;i++)
        ans[i][A-j-1] = count++;

        for(int i=A-j-2;i>=j;i--)
        ans[A-j-1][i] = count++;

        for(int i=A-j-2;i>j;i--)
        ans[i][j] = count++;
        
        j++;
    }
    return ans;
}

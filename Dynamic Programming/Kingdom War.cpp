int Solution::solve(vector<vector<int> > &A) {
    if(A.size() == 0)
    return 0;
    int row = A.size(),col = A[0].size(),sum,ans = INT_MIN;
    for(int i=row-1;i>=0;i--)
    {
        sum = 0;
        for(int j=col-1;j>=0;j--)
        {
            if(i!=row-1)
            A[i][j] = A[i][j] + A[i+1][j];
            sum = sum + A[i][j];
            ans = max(ans,sum);
        }
    }
    return ans;
}

int Solution::maxProfit(const vector<int> &A) {
    if(A.size()==0)
    return 0;
    int n = A.size(),profit = 0,m = A[0];
    vector<int> left(n,0),right(n,0);
    for(int i=1;i<n;i++)
    {
        m = min(A[i],m);
        left[i] = max(left[i-1],A[i]-m);
    }
    m = A[n-1];
    for(int i=n-2;i>=0;i--)
    {
        m = max(m,A[i]);
        right[i] = max(right[i+1],m-A[i]);
    }
    for(int i=0;i<n;i++)
    profit = max(profit,left[i]+right[i]);
    return profit;
}

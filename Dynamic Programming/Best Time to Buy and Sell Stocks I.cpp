int Solution::maxProfit(const vector<int> &A) {
    int n = A.size(),m = INT_MAX,profit = 0;
    for(int i=0;i<n;i++)
    {
        m = min(m,A[i]);
        profit = max(profit,A[i] - m);
    }
    return profit;
}

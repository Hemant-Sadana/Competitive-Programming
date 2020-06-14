int Solution::maxProfit(const vector<int> &A) {
    int n = A.size(),profit = 0;
    for(int i=1;i<n;i++)
    {
        if(A[i]>A[i-1])
        profit += A[i] - A[i-1];
    }
    return profit;
}

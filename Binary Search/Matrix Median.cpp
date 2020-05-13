int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size(),m = A[0].size();
    int low = INT_MAX,high = INT_MIN,mid,k;
    for(int i=0;i<n;i++)
    {
        low = min(low,A[i][0]);
        high = max(high,A[i][m-1]);
    }
    while(low<high)
    {
        mid = low + (high - low)/2;
        k = 0;
        for(int i=0;i<n;i++)
        {
            k += (upper_bound(A[i].begin(),A[i].end(),mid) - A[i].begin());
        }
        if(k>((m*n)/2))
        high = mid;
        else
        low = mid+1;
    }
    return low;
}

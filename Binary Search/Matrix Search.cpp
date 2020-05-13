int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int row = A.size(),col = A[0].size(),low,high,mid;
    low = 0;high = row-1;
    row = 0;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(A[mid][0]==B)
        return 1;
        if(A[mid][0] > B)
        high = mid-1;
        else
        {
            row = mid;
            low = mid+1;
        }
    }
    low = 0;high = col-1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(A[row][mid] == B)
        return 1;
        if(A[row][mid] > B)
        high = mid-1;
        else
        low = mid+1;
    }
    return 0;
}

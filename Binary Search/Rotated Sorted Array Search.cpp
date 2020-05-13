int Solution::search(const vector<int> &A, int B) {
    int n = A.size(),low = 0,high = n-1,mid;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(A[mid] == B)
        return mid;
        if(A[mid] > A[0])
        {
            if(A[0]<=B && A[mid]>B)
            high = mid-1;
            else
            low = mid+1;
        }
        else
        {
            if(A[n-1]>=B && A[mid]<B)
            low = mid+1;
            else high = mid-1;
        }
    }
    return -1;
}

int Solution::sqrt(int A) {
    if(A==0)
    return 0;
    int mid,low = 1,high = A;
    while(low<=high)
    {
        mid = (low + (high-low)/2);
        if(mid == A/mid)
        return mid;
        if(mid<A/mid && (mid+1) > A/(mid+1))
        return mid;
        if(mid>A/mid)
        high = mid-1;
        else
        low = mid+1;
    }
}

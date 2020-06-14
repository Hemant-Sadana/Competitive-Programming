int Solution::canJump(vector<int> &A) {
    int n = A.size(),reach = n-1;
    for(int i=n-2;i>=0;i--)
    {
        if(i+A[i]>=reach)
        reach = i;
    }
    return !reach;
}

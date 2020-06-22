int Solution::maxProduct(const vector<int> &A) {
    int n = A.size(),prevmx,prevmn,curmx,curmn,ans;
    prevmx = A[0];prevmn = A[0];ans = A[0];
    for(int i=1;i<n;i++)
    {
        curmx = max(prevmx*A[i],max(prevmn*A[i],A[i]));
        curmn = min(prevmn*A[i],min(prevmx*A[i],A[i]));
        prevmx = curmx;
        prevmn = curmn;
        ans = max(ans,curmx);
    }
    return ans;
}

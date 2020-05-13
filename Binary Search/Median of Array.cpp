double find(const vector<int> &A, const vector<int> &B)
{
    int n = A.size(),m = B.size();
    if(n==0)
    {
        if(m%2)
        return B[m/2];
        return (B[m/2 -1] + B[m/2])/2.0;
    }
    int low = 0,high = n,partx,party,lmin,lmax,rmin,rmax;
    while(low<=high)
    {
        partx = (low + high)/2;
        party = (m+n+1)/2 - partx;
        lmin = partx == 0 ? INT_MIN : A[partx-1];
        rmin = party ==0 ? INT_MIN : B[party-1];
        
        lmax = partx == n ? INT_MAX : A[partx];
        rmax = party == m ? INT_MAX : B[party];
        
        if(lmin>rmax)
        high = partx-1;
        else if(rmin>lmax)
        low = partx+1;
        else
        {
            if((m+n)%2)
            return max(lmin,rmin);
            return (max(lmin,rmin) + min(lmax,rmax))/2.0;
        }
    }
}
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int n = A.size(),m=B.size();
    if(n<=m)
    return find(A,B);
    return find(B,A);
}

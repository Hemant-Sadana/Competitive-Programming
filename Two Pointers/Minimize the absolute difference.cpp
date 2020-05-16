int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int y1 = A.size(),y2 = B.size(),y3 = C.size(),i = 0,j = 0,k = 0;
    int diff = INT_MAX,mx,mn;
    while(i<y1 && j<y2 && k<y3)
    {
        mx = max(A[i],max(B[j],C[k]));
        mn = min(A[i],min(B[j],C[k]));
        diff = min(diff,mx - mn);
        if(mn == A[i])
        i++;
        else if(mn == B[j])
        j++;
        else
        k++;
    }
    return diff;
}

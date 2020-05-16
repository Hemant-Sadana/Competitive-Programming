int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int y1 = A.size(),y2 = B.size(),y3 = C.size(),i = 0,j = 0,k = 0,ans = INT_MAX;
    int a,b,c,d;
    while(i<y1 && j<y2 && k<y3)
    {
        a = abs(A[i]-B[j]);b = abs(B[j]-C[k]);c = abs(C[k]-A[i]);
        d = max(a,max(b,c));
        ans = min(ans,d);
        a = min(A[i],min(B[j],C[k]));
        if(A[i]==a)
        i++;
        else if(B[j]==a)
        j++;
        else
        k++;
    }
    return ans;
}

int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size(),i = 0,j = 1;;
    while(i<n && j<n)
    {
        j = max(j,i+1);
        if(A[j]-A[i]==B)
        return 1;
        if(A[j]-A[i]>B)
        i++;
        else
        j++;
    }
    return 0;
}

int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size(),k = 1;
    for(int i=1;i<n;i++)
    {
        if(A[i]==A[i-1])
        continue;
        A[k++] = A[i]; 
    }
    A.resize(k);
    return k;
}

int Solution::removeElement(vector<int> &A, int B) {
    int n = A.size(),k = 0;
    for(int i=0;i<n;i++)
    {
        if(A[i]!=B)
        A[k++] = A[i];
    }
    return k;
}

int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size(),k = 1, c = 1;
    for(int i=1;i<n;i++)
    {
        if(A[i] == A[i-1])
        {
            if(c==1)
            {
                A[k++] = A[i];
                c = 2;
            }
        }
        else
        {
            A[k++] = A[i];
            c = 1;
        }
    }
    A.resize(k);
    return k;
}

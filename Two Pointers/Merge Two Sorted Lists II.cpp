void Solution::merge(vector<int> &A, vector<int> &B) {
    int n = A.size(),m = B.size();
    A.resize(m+n);
    int i = n-1,j = m-1, k = m+n-1;
    while(j>=0)
    {
        if(i>=0 && A[i] > B[j])
        {
            A[k] = A[i];
            i--;
        }
        else if(i<0 || A[i]<=B[j])
        {
            A[k] = B[j];
            j--;
        }
        k--;
    }
}

int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    int c = 0,k,n = A.size();
    for(int i=0;i<n-2;i++)
    {
        k = i+2;
        for(int j=i+1;j<n-1;j++)
        {
            while(k<n && (A[i]+A[j]>A[k]))
            k++;
            c = (c + (k-j-1))%(int)(1e9+7);
        }
    }
    return c;
}

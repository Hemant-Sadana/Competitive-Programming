int Solution::strStr(const string A, const string B) {
    int n = A.size(),m = B.size(),flag = 0,i,j;
    if(m==0)
    return -1;
    if(n==0)
    return 0;
    /*KMP ALGORITHM*/
    vector<int> preprocess(m,0);
    i = 1;j = 0;
    while(i<m)
    {
        if(B[j] == B[i])
        {
            preprocess[i] = j+1;
            j++;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j = preprocess[j-1];
            }
            else
            {
                preprocess[i] = 0;
                i++;
            }
        }
    }
    i = 0;j = 0;
    while(i<n && j<m)
    {
        if(A[i]==B[j])
        {
            i++;j++;
            if(j==m)
            return i-m;
        }
        else
        {
            if(j!=0)
            j = preprocess[j-1];
            else
            i++;
        }
    }
    return -1;
}

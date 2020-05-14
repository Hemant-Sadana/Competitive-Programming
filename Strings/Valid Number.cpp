int Solution::isNumber(const string A) {
    int n = A.size(),e = 0, dec = 0, sig = 0,j,i;
    while(A[j]==' ' && j<n)
    j++;
    if(j==n)
    return 0;
    for(i=j;i<n;i++)
    {
        if(A[i]=='e')
        {
            if(e==1 || i==0 || !(A[i-1]>='0' && A[i-1]<='9') || i==n-1)
            return 0;
            sig = 0;dec = 1;e = 1;
        }
        else if(A[i]=='.')
        {
            if(i==n-1 || dec==1 || !(A[i+1]>='0' && A[i+1]<='9'))
            return 0;
            dec = 1;
        }
        else if(A[i]=='+' || A[i]=='-')
        {
            if(sig==1 || i==n-1 || !(A[i+1]>='0' && A[i+1]<='9'))
            return 0;
            sig = 1;
        }
        else if(A[i]>='0' && A[i]<='9')
        continue;
        else if(A[i]==' ')
        break;
        else return 0;
    }
    while(i<n && A[i]==' ')
    i++;
    return i==n ? 1 : 0;
}

int Solution::power(string A) {
    int n = A.size(),i,j,q;
    if(n==0 || A=="1" || A=="0" || A[0]=='-')
    return 0;
    string temp="";
    while(1)
    {
        j = 0;q = 0;
        while(A[j]=='0' && j<n)
        j++;
        if(j==n-1 && A[j]=='1')
        return 1;
        if(j==n || (A[n-1]-48)%2)
        return 0;
        for(i=j;i<n;i++)
        {
            q = (q*10 + A[i]-48);
            A[i] = (q/2)+'0';
            q = q%2;
        }
    }
}

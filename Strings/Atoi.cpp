int Solution::atoi(const string A) {
    int n = A.size(),sign,i,num = 0;
    for(i=0;i<n;i++)
    {
        if(A[i]==' ')
        continue;
        if(A[i]>='0' && A[i]<='9' || A[i]=='+' || A[i]=='-')
        break;
        return 0;
    }
    if(i==n)
    return 0;
    if(A[i]=='+')
    {
        sign = 0;
        i++;
    }
    if(A[i]=='-')
    {
        sign = 1;
        i++;
    }
    for(int j=i;j<n;j++)
    {
        if(!(A[j]>='0' && A[j]<='9'))
        return (sign==0) ? num : -num;
        if(num>INT_MAX/10 || num == INT_MAX/10 && A[i]>'7')
        return (sign==0) ? INT_MAX : INT_MIN;
        num = num*10 + (A[j]-48);
    }
}

int Solution::isPower(int A) {
    if(A==1)
    return 1;
    int y,n=sqrt(A);
    for(int i=2;i<=n;i++)
    {
        y = log(A)/log(i);
        if(pow(i,y)==A)
        return 1;
    }
    return 0;
}

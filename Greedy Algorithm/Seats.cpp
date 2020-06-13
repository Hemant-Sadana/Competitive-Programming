int Solution::seats(string A) {
    int n = A.size(),count = 0,c,l = 0,r = n,i;
    for(i=0;i<n;i++)
    {
        if(A[i]=='x')
        count++;
    }
    c = ceil(count/2.0);
    for(i=0;i<n;i++)
    {
        if(A[i]=='x')
        c--;
        if(c == 0)
        break;
    }
    c = 0;
    l = i-1;r = i+1;
    for(i=l;i>=0;i--)
    {
        if(A[i] == 'x')
        {
            c = (c + abs(i-l))%10000003;
            l--;
        }
    }
    for(i=r;i<n;i++)
    {
        if(A[i] == 'x')
        {
            c = (c + abs(i-r))%10000003;
            r++;
        }
    }
    return c;
}

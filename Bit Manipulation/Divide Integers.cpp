int Solution::divide(int A, int B) {
    if(B==0 || A == INT_MIN && B == -1)
    return INT_MAX;
    if(A==0)
    return 0;
    int x,ans = 0;
    long int a = A,b = B;
    long int c = abs(a),d = abs(b);
    while(c-d>=0)
    {
        x = 0;
        while(c - (d<<1<<x) >= 0)
        x++;
        ans = ans + (1<<x);
        c = c - (d<<x);
    }
    if(A<0 && B>0 || A>0 && B<0)
    return -ans;
    return ans;
}

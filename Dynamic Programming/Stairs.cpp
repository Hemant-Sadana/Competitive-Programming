int Solution::climbStairs(int A) {
    int a = 1,b = 2,c = 0;
    if(A<=2)
    return A;
    for(int i=3;i<=A;i++)
    {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

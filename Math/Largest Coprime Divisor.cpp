int gcd(int A,int B)
{
    while(A!=B)
    {
        A>B ? A = A-B : B = B-A;
    }
    return A;
}
int Solution::cpFact(int A, int B) {
    while(gcd(A,B)!=1)
    {
        A = A/gcd(A,B);
    }
    return A;
}

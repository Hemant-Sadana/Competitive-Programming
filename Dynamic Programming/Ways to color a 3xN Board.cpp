int Solution::solve(int A) {
    long int three = 24,two = 12,temp;
    for(int i = 1;i<A;i++)
    {
        temp = three;
        three = ((11*three)%1000000007 + (10*two)%1000000007)%1000000007;
        two = ((5*temp)%1000000007 + (7*two)%1000000007)%1000000007;
    }
    return (two + three)%1000000007;
}

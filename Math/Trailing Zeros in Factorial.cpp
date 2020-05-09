int Solution::trailingZeroes(int A) {
    int zeros = 0,t = 5;
    while(t<=A)
    {
        zeros += A/t;
        t = t*5; 
    }
    return zeros;
}

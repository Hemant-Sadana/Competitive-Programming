int Solution::titleToNumber(string A) {
    int sum = 0,n = A.size();
    for(int i=0;i<n;i++)
    {
        sum += (pow(26,(n-i-1))*(A[i]-64));
    }
    return sum;
}

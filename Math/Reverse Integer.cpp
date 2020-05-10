int Solution::reverse(int A) {
    int ans = 0;
    int x = abs(A);
    while(x>0)
    {
        if(ans > (INT_MAX/10) || (ans == INT_MAX/10 && x%10 > INT_MAX%10))
        return 0;
        ans = ans*10 + x%10;
        x = x/10;
    }
    if(A<0)
    return -ans;
    return ans;
}

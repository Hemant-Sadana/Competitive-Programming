long long int power(int x,int n,int d)
{
    if(n==1)
    return x;
    if(n%2==0)
    return ((power(x,n/2,d)%d)*(power(x,n/2,d)%d))%d;
    else
    return ((x%d)*(power(x,n-1,d)%d))%d;
}
int Solution::pow(int x, int n, int d) {
    if(x==0 && n==0)
    return 0;
    if(n==0)
    return 1;
    int ans = power(x,n,d);    
    return ans<0 ?  d + ans : ans;
}

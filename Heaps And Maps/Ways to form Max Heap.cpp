#define MOD 1000000007
vector<vector<long int> > comb;
vector<int> lefty;
vector<long int> dp;
long int findcomb(long int n,long int r)
{
    if(n<0)
    return 0;
    if(r==0 || n==r)
    return 1;
    if(comb[n][r]!=-1)
    return comb[n][r];
    return comb[n][r] = (findcomb(n-1,r)%MOD + findcomb(n-1,r-1)%MOD)%MOD;
}
int findleft(int n)
{
    if(lefty[n]!=0 || n==0)
    return lefty[n];
    int h = log(n)/log(2);
    int last = pow(2,h)-1;
    int p = n - last;
    int x = (last+1)/2;
    if(p >= x)
    return lefty[n] = last;
    return lefty[n] = last - (x - p);
}
int find(int A)
{
    if(A==0 || A==1)
    return A;
    if(A==2)
    return 1;
    if(dp[A]!=-1)
    return dp[A];
    
    int l = findleft(A);
    int r = A-l-1;
    return dp[A] = (((findcomb(A-1,l)*find(l))%MOD)*find(r))%MOD;
}
int Solution::solve(int A) {
    comb.resize(A+1,vector<long int> (A+1,-1));
    lefty.resize(A+1,0);
    dp.resize(A+1,-1);
    return find(A);
}

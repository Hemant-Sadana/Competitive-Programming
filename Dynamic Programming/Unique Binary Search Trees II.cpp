int Solution::numTrees(int A) {
    unsigned long int n = 2*A,r = A,ans = 1;
    for(int i=1;i<=A;i++)
    {
        ans = (ans * n)/i;
        n--;
    }
    ans = ans/(A+1);
    return ans;
}

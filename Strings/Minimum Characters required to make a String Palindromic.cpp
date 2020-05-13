bool ispallin(string A,int n)
{
    int i=0,j=n;
    while(i<j)
    {
        if(A[i]!=A[j])
        return false;
        i++;
        j--;
    }
    return true;
}
int Solution::solve(string A) {
    int n = A.size();
    for(int i=n-1;i>=0;i--)
    {
        if(ispallin(A,i))
        return n-i-1;
    }
}

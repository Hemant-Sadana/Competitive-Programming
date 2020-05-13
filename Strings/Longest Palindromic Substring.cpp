bool ispalin(string A,int i,int j)
{
    while(i<j)
    {
        if(A[i]!=A[j])
        return false;
        i++;j--;
    }
    return true;
}
string Solution::longestPalindrome(string A) {
    int n = A.size(),s,e,m=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=i;j--)
        {
            if(j-i<m)
            break;
            if(ispalin(A,i,j))
            {
                if(j-i>m)
                {
                    m = j-i;
                    s = i;
                    e = j;
                }
                break;
            }
        }
    }
    string temp="";
    for(int i=s;i<=e;i++)
    temp+=A[i];
    return temp;
}

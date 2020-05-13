int Solution::solve(string A) {
    int n = A.size(),count = 0;
    char c;
    for(int i=0;i<n;i++)
    {
        c = toupper(A[i]);
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        count = (count + (n-i))%10003;
    }
    return count;
}

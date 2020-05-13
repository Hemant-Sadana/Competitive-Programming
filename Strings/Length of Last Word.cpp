int Solution::lengthOfLastWord(const string A) {
    int n = A.size(),i = n-1,c = 0;
    while(i>=0 && A[i]==' ')
    i--;
    while(i>=0 && A[i]!=' ')
    {
        i--;c++;
    }
    return c;
}

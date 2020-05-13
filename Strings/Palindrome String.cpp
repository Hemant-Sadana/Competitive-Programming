int Solution::isPalindrome(string A) {
    int n = A.size(),i=0,j=n-1;
    while(i<j)
    {
        if(!isalnum(A[i]))
        i++;
        else if(!isalnum(A[j]))
        j--;
        else if(toupper(A[i])!=toupper(A[j]))
        return 0;
        else
        {
            i++;
            j--;
        }
    }
    return 1;
}

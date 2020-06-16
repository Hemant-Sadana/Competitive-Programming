int Solution::numDecodings(string A) {
    int n = A.size(),c = 1;
    if(n == 0 || A[0]== '0')
    return 0;
    for(int i=1;i<n;i++)
    {
        if(A[i]== '0' && A[i-1] == '0')
        return 0;
        else if(A[i] == '0' && (A[i-1]-48) > 2)
        return 0;
        else if(A[i-1] == '0')
        continue;
        else if(i==1 && A[i] == '0')
        continue;
        else if(A[i] == '0' && ((A[i-2]-48)*10 + (A[i-1]-48) > 26))
        continue;
        else if(A[i] == '0' && ((A[i-2]-48)*10 + (A[i-1]-48) <= 26))
        c = ceil(c/2.0);
        else if((A[i-1]-48)*10 + (A[i]-48) > 26)
        continue;
        else
        {
            if(i == 1 || (A[i-2]-48)*10 + (A[i-1]-48) <= 26)
            c = c + ceil(c/2.0);
            else
            c = c*2;
        }
    }
    return c;
}

string Solution::solve(string A) {
    int n = A.size(),i=0;
    string t1="",t2="";
    while(i<n)
    {
        while(A[i]==' ')
        {
            i++;
            continue;
        }
        while(i<n && A[i]!=' ')
        {
            t1 += A[i];
            i++;
        }
        t2 = (t2 == "") ? t1+t2 : t1+' '+t2;
        t1 = "";
    }
    return t2;
}

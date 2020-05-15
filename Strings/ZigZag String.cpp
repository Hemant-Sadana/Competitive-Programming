string Solution::convert(string A, int B) {
    if(B==1)
    return A;
    string temp="";
    int n = A.size(),gap = 2*B-3,j,c,igap,fgap = gap;
    for(int i = 0;i<B;i++)
    {
        j = i;c = 1;igap = gap;
        while(j<n)
        {
            temp+=A[j];
            if(c || gap == fgap)
            c = 0;
            else
            gap = fgap-1 - gap;
            j = j+gap+1;
        }
        gap = (igap-2)>0 ? igap-2 : fgap ;
    }
    return temp;
}

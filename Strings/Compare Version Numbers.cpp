int Solution::compareVersion(string A, string B) {
    int n = A.size(),m = B.size(),a,b,i=0,j=0,c,d;
    string t1="",t2="",x="",y="";
    while(i<n || j<m)
    {
        while(i<n && A[i]!='.')
        t1+=A[i++];
        while(j<m && B[j]!='.')
        t2+=B[j++];
        a = t1.size();b = t2.size();c=0;d=0;
        while(c<a)
        {
            if(t1[c]!='0')
            break;
            c++;
        }
        x = t1.substr(c);
        while(d<b)
        {
            if(t2[d]!='0')
            break;
            d++;
        }
        y = t2.substr(d);
        if(x.size()>y.size())
        return 1;
        if(x.size()<y.size())
        return -1;
        if(x>y)
        return 1;
        if(y>x)
        return -1;
        t1 = "";t2 = "";i++;j++;x = "";y = "";
    }
    return 0;
}

string Solution::countAndSay(int A) {
    if(A==0)
    return "";
    string t1 = "1",t2 = "";
    int count = 1,n;
    for(int i=1;i<A;i++)
    {
        n = t1.size();
        for(int j=0;j<n;j++)
        {
            if(j==t1.size()-1 || t1[j]!=t1[j+1])
            {
                t2+=to_string(count);
                t2+=t1[j];
                count = 1;
            }
            else
            count++;
        }
        t1 = t2;
        t2 = "";
    }
    return t1;
}

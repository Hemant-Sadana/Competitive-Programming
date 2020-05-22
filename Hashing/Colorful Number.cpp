int Solution::colorful(int A) {
    int n,p = 1;
    map<int,int> hash;
    while(A>0)
    {
        p = 1;n = A;
        while(n>0)
        {
            p = p*(n%10);
            if(hash.find(p)!=hash.end())
            return 0;
            hash[p] = 1;
            n = n/10;
        }
        A = A/10;
    }
    return 1;
}

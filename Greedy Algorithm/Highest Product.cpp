int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    int a = INT_MIN,b = INT_MIN, c = INT_MIN,d = INT_MAX,e = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(A[i]>a)
        {
            c = b;
            b = a;
            a = A[i];
        }
        else if(A[i]>b)
        {
            c = b;
            b = A[i];
        }
        else if(A[i]>c)
        c = A[i];
        if(A[i]<d)
        {
            e = d;
            d = A[i];
        }
        else if(A[i]<e)
        e = A[i];
    }
    return max(a*b*c,a*d*e);
}

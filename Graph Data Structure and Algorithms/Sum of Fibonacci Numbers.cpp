int Solution::fibsum(int A) {
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);
    int a = 1,b = 1,c,steps = 0,n;
    while(a+b<=A)
    {
        c = a+b;
        fib.push_back(c);
        a = b;
        b = c;
    }
    n = fib.size()-1;
    while(1)
    {
        if(A == 0)
        return steps;
        if(A>=fib[n])
        {
            A = A-fib[n];
            steps++;
        }
        else
        n--;
    }
}

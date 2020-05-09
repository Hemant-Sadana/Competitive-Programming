bool prime(int n)
{
    int t = sqrt(n);
    for(int i=2;i<=t;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
vector<int> Solution::primesum(int A) {
    vector<int> ans;
    for(int i=2;i<A;i++)
    {
        if(prime(i))
        {
            if(prime(A-i))
            {
                ans.push_back(i);
                ans.push_back(A-i);
                return ans;
            }
        }
    }
}

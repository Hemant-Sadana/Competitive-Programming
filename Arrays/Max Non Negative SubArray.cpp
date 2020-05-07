vector<int> Solution::maxset(vector<int> &A) {
    int n = A.size(),start=-1,end;
    long int sum=0,count = 0,ans = INT_MIN,len=0;
    for(int i=0;i<=n;i++)
    {
        if(A[i]<0 || i==n)
        {
            if(sum>ans || (sum==ans && count>len))
            {
                ans = sum;
                len = count;
                start = i-count;
                end = i-1;
            }
            sum = 0;
            count = 0;
        }
        else
        {
            sum+=A[i];
            count++;
        }
    }
    vector<int> sol;
    if(start==-1)
    return sol;
    for(int i=start;i<=end;i++)
    sol.push_back(A[i]);
    return sol;
}

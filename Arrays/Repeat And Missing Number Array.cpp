vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long int n = A.size(),repeat,missing,s1 = 0,s2 = 0;
    for(long int i=1;i<=n;i++)
    {
        s1 += (A[i-1]-i);           
        s2 += (A[i-1]-i)*(A[i-1]+i);
    }
    s2 = s2/s1;
    repeat = (s1+s2)/2;
    missing = repeat - s1;
    vector<int> ans;
    ans.push_back(repeat);
    ans.push_back(missing);
    return ans;
}

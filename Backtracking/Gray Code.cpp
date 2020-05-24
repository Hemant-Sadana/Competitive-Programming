vector<int> Solution::grayCode(int A) {
    vector<int> ans(1,0);
    int n,mul = 1;
    for(int i=0;i<A;i++)
    {
        n = ans.size();
        for(int j=n-1;j>=0;j--)
        ans.push_back(ans[j] + mul);
        mul = mul<<1;
    }
    return ans;
}

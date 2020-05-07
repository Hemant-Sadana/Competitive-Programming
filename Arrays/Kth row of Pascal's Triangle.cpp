vector<int> Solution::getRow(int A) {
    vector<int> ans;
    ans.push_back(1);
    int i=0,res = 1;
    while(i<A)
    {
        res = res*(A-i)/(i+1);
        ans.push_back(res);
        i++;
    }
    return ans;
}

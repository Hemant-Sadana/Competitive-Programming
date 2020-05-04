vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size(),sum = 0,c=1,i;
    vector<int> ans;
    i = n-1;
    while(i>=0)
    {
        sum = A[i] + c;
        c = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    if(c==1)
    ans.push_back(c);
    reverse(ans.begin(),ans.end());
    for(i=0;i<ans.size();i++)
    {
        if(ans[i]!=0)
        break;
    }
    ans.erase(ans.begin(),ans.begin()+i);
    return ans;
}

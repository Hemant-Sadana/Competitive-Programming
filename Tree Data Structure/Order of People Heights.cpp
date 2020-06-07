vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    map<int,int> height;
    int n = A.size();
    for(int i=0;i<n;i++)
    height[A[i]] = B[i];
    vector<int> temp(n),ans(n);
    for(int i=0;i<n;i++)
    temp[i] = i;
    for(auto k = height.begin();k!=height.end();k++)
    {
        ans[temp[k->second]] = k->first;
        temp.erase(temp.begin()+ k->second);
    }
    return ans;
}

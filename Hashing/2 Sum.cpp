vector<int> Solution::twoSum(const vector<int> &A, int B) {
    vector<int> ans;
    int n = A.size();
    map<int,int> hash;
    for(int i=0;i<n;i++)
    {
        if(hash.find(B - A[i])!=hash.end())
        {
            ans.push_back(hash[B-A[i]]+1);
            ans.push_back(i+1);
            return ans;
        }
        if(hash.find(A[i])==hash.end())
        hash[A[i]] = i;
    }
    return ans;
}

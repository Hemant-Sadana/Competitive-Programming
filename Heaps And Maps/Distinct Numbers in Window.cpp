vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int,int> hash;
    vector<int> ans;
    int n = A.size();
    for(int i=0;i<B;i++)
    hash[A[i]]++;
    ans.push_back(hash.size());
    for(int i=B;i<n;i++)
    {
        hash[A[i]]++;
        hash[A[i-B]]--;
        if(hash[A[i-B]]==0)
        hash.erase(A[i-B]);
        ans.push_back(hash.size());
    }
    return ans;
}

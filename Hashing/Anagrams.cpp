vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    int n = A.size(),k = 0;
    unordered_map<string,vector<int> > hash;
    vector<vector<int> > ans;
    string temp = "";
    for(int i=0;i<n;i++)
    {
        temp = A[i];
        sort(temp.begin(),temp.end());
        hash[temp].push_back(i+1);
    }
    for(auto i = hash.begin();i != hash.end();i++)
    ans.push_back(i->second);
    return ans;
}

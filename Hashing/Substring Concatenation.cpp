vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int n = A.size(),y = B.size(),len = B[0].size(),c = 0,k = 0;
    vector<int> ans;
    string temp;
    map<string,int> hash1,hash2;
    for(int i=0;i<y;i++)
    hash1[B[i]]++;
    hash2 = hash1;
    int i = 0;
    while(i+len<=n)
    {
        temp = A.substr(i,len);
        if(hash2.find(temp) == hash2.end())
        {
            k++;i = k;hash2 = hash1;c = 0;
        }
        else
        {
            hash2[temp]--;
            c++;
            if(hash2[temp]==0)
            hash2.erase(temp);
            if(c == y)
            {
                ans.push_back(k);
                hash2 = hash1;
                k++;i = k;c = 0;
            }
            else
            i = i + len;
        }
    }
    return ans;
}

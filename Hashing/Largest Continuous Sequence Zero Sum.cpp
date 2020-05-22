vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size(),s=0,e=-1,max_len = INT_MIN,len,sum = 0;
    map<int,int> hash;
    hash[0] = -1;
    for(int i=0;i<n;i++)
    {
        sum += A[i];
        if(hash.find(sum)!=hash.end())
        {
            len = i - hash[sum];
            if(len>max_len)
            {
                max_len = len;s = hash[sum]+1;e = i;
            }
        }
        else
        hash[sum] = i;
    }
    vector<int> ans;
    for(int i=s;i<=e;i++)
    ans.push_back(A[i]);
    return ans;
}

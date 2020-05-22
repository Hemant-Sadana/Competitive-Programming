int Solution::lengthOfLongestSubstring(string A) {
    int n = A.size(),k = 0,len = 0,max_len = 0,s;
    map<char,int> hash;
    for(int i=0;i<n;i++)
    {
        if(hash.find(A[i]) == hash.end())
        {
            len++;
            hash[A[i]] = i;
        }
        else
        {   
            max_len = max(len,max_len);
            s = hash[A[i]];
            while(k<=s)
            {
                hash.erase(A[k]);
                k++;
            }
            hash[A[i]] = i;
            len = i - k + 1; 
        }
    }
    return max(len,max_len);
}

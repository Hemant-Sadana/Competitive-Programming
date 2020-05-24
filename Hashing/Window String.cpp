string Solution::minWindow(string A, string B) {
    int y1 = A.size(),y2 = B.size(),k = 0,start = -1,i,j,minw = INT_MAX,l = 1;
    if(y2>y1)
    return "";
    map<char,int> hash1,hash2,hash3;
    vector<int> temp;
    for(i=0;i<y2;i++)
    hash1[B[i]]++;
    hash2 = hash1;
    for(i=0;i<y1;i++)
    {
        if(hash1.find(A[i])!=hash1.end())
        {
            hash3[A[i]]++;
            temp.push_back(i);
        }
        if(hash2.find(A[i])!=hash2.end())
        {
            hash2[A[i]]--;
            if(hash2[A[i]] == 0)
            {
                hash2.erase(A[i]);
            }
            if(hash2.size()==0)
            {
                l = 1;
                while(l || hash3[A[temp[k-1]]] >= hash1[A[temp[k-1]]])
                {
                    l = 0;
                    hash3[A[temp[k]]]--;
                    if((i - temp[k]  + 1)<minw)
                    {
                    minw = i - temp[k]  + 1;
                    start = temp[k];
                    }
                    k++;
                }
                hash2[A[temp[k-1]]]  = 1;
            }
        }
    }
    string t = "";
    if(start == -1)
    return "";
    t = A.substr(start,minw);
    return t;
}

int Solution::diffPossible(const vector<int> &A, int B) {
    int n = A.size();
    map<int,int> hash;
    for(int i=0;i<n;i++)
    {
        if(hash.find(A[i]-B)!=hash.end() || hash.find(A[i]+B)!=hash.end())
        return 1;
        hash[A[i]] = 1;
    }
    return 0;
}

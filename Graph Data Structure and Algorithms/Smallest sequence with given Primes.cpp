vector<int> Solution::solve(int A, int B, int C, int D) {
    map<int,int> hash;
    vector<int> ans;
    hash[A] = 1;hash[B] = 1;hash[C] = 1;
    int c = 0,num;
    while(c<D)
    {
        num = (hash.begin())->first;
        hash.erase(num);
        ans.push_back(num);
        hash[num*A] = 1;
        hash[num*B] = 1;
        hash[num*C] = 1;
        c++;
    }
    return ans;
}

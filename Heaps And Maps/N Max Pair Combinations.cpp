vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int n = A.size(),c = 0,i,j;
    priority_queue<pair<int,pair<int,int> > > heap;
    pair<int,pair<int,int> > temp;
    map<pair<int,int>,int> dup;
    heap.push(make_pair(A[n-1]+B[n-1],make_pair(n-1,n-1)));
    dup[make_pair(n-1,n-1)] = 1;
    vector<int> ans;
    while(c<n)
    {
        temp = heap.top();
        ans.push_back(temp.first);
        heap.pop();
        i = temp.second.first;j = temp.second.second;
        if(dup.find(make_pair(i-1,j))==dup.end())
        {
            dup[make_pair(i-1,j)] = 1;
            heap.push(make_pair(A[i-1]+B[j],make_pair(i-1,j)));
        }
        if(dup.find(make_pair(i,j-1))==dup.end())
        {
            dup[make_pair(i,j-1)] = 1;
            heap.push(make_pair(A[i]+B[j-1],make_pair(i,j-1)));
        }
        c++;
    }
    return ans;
}

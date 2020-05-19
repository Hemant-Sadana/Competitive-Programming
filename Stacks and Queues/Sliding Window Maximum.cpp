vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n = A.size(),j;
    vector<int> ans;
    deque<int> q;
    for(int i=0;i<B;i++)
    {
        while(!q.empty() && A[i]>=A[q.back()])
        q.pop_back();
        q.push_back(i);
    }
    ans.push_back(A[q.front()]);
    for(int i=B;i<n;i++)
    {
        while(!q.empty() && A[i]>=A[q.back()])
        q.pop_back();
        while(!q.empty() && i-B>=q.front())
        q.pop_front();
        q.push_back(i);
        ans.push_back(A[q.front()]);
    }
    return ans;
}

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<long int> heap(B.begin(),B.end());
    int n = B.size();
    long long int high,sum = 0;
    for(int i=0;i<A;i++)
    {
        high = heap.top();
        heap.pop();
        sum = (sum+high);
        high = high/2;
        heap.push(high);
    }
    return sum%int(1e9+7);
}

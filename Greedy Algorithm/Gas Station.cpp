int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size(),cost = 0,ind = 0,to_cover = 0;
    for(int i=0;i<n;i++)
    {
        cost = cost + A[i] - B[i];
        if(cost<0)
        {
            ind = i+1;
            to_cover += cost;
            cost = 0;
        }
    }
    return (cost < abs(to_cover)) ? -1 : ind;
}

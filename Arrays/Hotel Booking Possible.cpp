bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    int n = arrive.size(),dep = 0;
    for(int i=0;i<n;i++)
    {
        if(K==0)
        {
            if(arrive[i]>=depart[dep])
            {
                K++;
                dep++;
            }
        }
        K--;
        if(K<0)
        return 0;
    }
    return 1; 
}

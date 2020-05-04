/* Need to find the contigous array of maximum 0's (We can reduce this problem to max sum contiguous subarray by converting 0's to 1
and 1's to -1) */
vector<int> Solution::flip(string A) {
    int n = A.size(),sum=0,maxsum=INT_MIN,start=-1,end,count = 0;;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='1')
        ans.push_back(-1);
        else
        ans.push_back(1);
    }
    for(int i=0;i<n;i++)
    {
        sum += ans[i];
        count++;
        if(sum<0)
        {
            sum = 0;    
            count = 0;
        }
        else if(sum>maxsum)
        {
            maxsum = max(maxsum,sum);
            start = i - count + 1;
            end = i;
        }
    }
    ans.clear();
    if(start == -1)
    return ans;
    ans.push_back(start+1);
    ans.push_back(end+1);
    return ans;
}

vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size(),flips = B,sum = 0,max = -1,end,k = 0;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(A[i]==0)
        {
            flips--;
            if(flips<0)
            {
                if(sum > max)
                {
                    max = sum;
                    end = i;
                }
                flips = 0;
                sum = (B==0)? 0 : i - ans[k];
                k++;
            }
            else
            sum = sum+1;
            ans.push_back(i);
        }
        else
        {
            sum = sum + 1;
        }
    }
    if(sum>max)
    {
        max = sum;
        end = n;
    }
    end--;
    ans.clear();
    for(int i = 0;i<max;i++)
    ans.push_back(end--);
    reverse(ans.begin(),ans.end());
    return ans;
}

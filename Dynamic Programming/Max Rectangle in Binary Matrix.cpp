int hist(vector<int> &A)
{
    int n = A.size(),ans = 0;
    stack<int> st,ind;
    vector<int> left(n,-1),right(n,n);
    st.push(A[0]);
    ind.push(0);
    for(int i=1;i<n;i++)
    {
        while(!st.empty() && st.top()>=A[i])
        {
            st.pop();ind.pop();
        }
        if(!st.empty())
        left[i] = ind.top();
        st.push(A[i]);
        ind.push(i);
    }
    while(!st.empty())
    {
        st.pop();ind.pop();
    }
    st.push(A[n-1]);
    ind.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!st.empty() && st.top()>=A[i])
        {
            st.pop();ind.pop();
        }
        if(!st.empty())
        right[i] = ind.top();
        st.push(A[i]);
        ind.push(i);
    }
    for(int i=0;i<n;i++)
    ans = max(ans,A[i]*(right[i] - (left[i]+1)));
    return ans;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int row = A.size(),col = A[0].size(),area = 0;
    vector<int> dp(col,0);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(A[i][j] == 1)
            dp[j] = dp[j] + 1;
            else
            dp[j] = 0;
        }
        area = max(area,hist(dp));
    }
    return area;
}

int Solution::trap(const vector<int> &A) {
    int n = A.size(),ans = 0,ix,m;
    stack<int> st,ind;
    vector<int> right(n,-1);
    ind.push(n-1);
    st.push(A[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        while(!st.empty() && A[i]>st.top())
        {
            ix = ind.top();
            st.pop();ind.pop();
        }
        if(!st.empty())
        right[i] = ind.top();
        else
        right[i] = ix;
        st.push(A[i]);
        ind.push(i);
    }
    m = min(A[0],A[right[0]]);
    for(int i=1;i<n-1;i++)
    {
        if(A[i]>=m)
        m = min(A[i],A[right[i]]);
        else
        ans += m - A[i];
    }
    return ans;
}

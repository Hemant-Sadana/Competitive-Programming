vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    stack<int> st;
    vector<int> ans(n,-1);
    st.push(A[0]);
    for(int i=1;i<n;i++)
    {
        while(!st.empty() && st.top() >= A[i])
        st.pop();
        if(!st.empty())
        ans[i] = st.top();
        st.push(A[i]);
    }
    return ans;
}

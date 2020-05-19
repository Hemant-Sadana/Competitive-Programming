int Solution::evalRPN(vector<string> &A) {
    int n = A.size(),a,b;
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")
        {
            a = st.top();st.pop();b = st.top();st.pop();
            if(A[i] == "+")
            {
                st.push(b+a);
            }
            else if(A[i] == "-")
            {
                st.push(b-a);
            }
            else if(A[i] == "*")
            {
                st.push(b*a);
            }
            else if(A[i] == "/")
            {
                st.push(b/a);
            }
        }
        else 
        st.push(stoi(A[i]));   
    }
    return st.top();
}

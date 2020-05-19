int Solution::braces(string A) {
    int n = A.size(),f = 0,flag = 1;;
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='(')
        {
            st.push('(');
            f++;
        }
        else if((A[i]=='+' || A[i] == '-' || A[i]=='*' || A[i]=='/') && f && flag)
        {
            f--;
            flag = 0;
            st.pop();
        }
        else
        flag = 1;
    }
    return st.empty() ? 0 : 1;
}

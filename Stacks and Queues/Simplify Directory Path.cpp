string Solution::simplifyPath(string A) {
    int n = A.size();
    stack<string> st;
    string temp="",ans = "";
    for(int i=0;i<n;i++)
    {
        if(A[i]=='/')
        {
            if(temp!="")
            {
                st.push(temp);
                temp = "";
            }
        }
        else if(A[i]=='.')
        {
            if(i!=n-1 && A[i+1]=='.')
            {
                if(!st.empty())
                st.pop();
                i++;
            }
        }
        else
        {
            temp=A[i]+temp;
            if(i==n-1)
            st.push(temp);
        }
    }
    while(!st.empty())
    {
        ans.append(st.top());
        ans.append("/");
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    if(ans == "")
    return "/";
    return ans;
}

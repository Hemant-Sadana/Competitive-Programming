int Solution::longestValidParentheses(string A) {
    stack<int> ind,check;
    int n = A.size(),prev = n,ans = INT_MIN,x;
    for(int i=0;i<n;i++)
    {
        if(A[i] == '(')
        {
            ind.push(i);check.push(i);
        }
        else
        {
            if(!check.empty())
            {
                check.pop();ind.pop();
            }
            else
            ind.push(i);
        }
    }
    while(!ind.empty())
    {
        x = ind.top();
        ans = max(ans,prev - x - 1);
        prev = x;
        ind.pop();
    }
    return max(ans,prev);
}

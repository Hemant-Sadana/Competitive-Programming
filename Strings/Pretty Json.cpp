vector<string> Solution::prettyJSON(string A) {
    int n = A.size(),space = 0,c = 1;
    string temp = "";
    vector<string> ans;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='{' || A[i]=='[')
        {
            if(temp!="")
            {
                ans.push_back(temp);
                temp = "";
            }
            for(int j=0;j<space;j++)
            temp+='\t';
            temp+=A[i];
            ans.push_back(temp);
            space++;
            temp = "";
            c = 1;
        }
        else if(A[i]=='}' || A[i]==']')
        {
            space--;
            if(temp!="")
            {
                ans.push_back(temp);
                temp = "";
            }
            for(int j=0;j<space;j++)
            temp+='\t';
            temp+=A[i];
            if(A[i+1]==',')
            {
                temp += ',';
                i++;
            }
            ans.push_back(temp);
            temp = "";
            c = 1;
        }
        else if(A[i]==',')
        {
            temp += A[i];
            if(A[i+1] == '}' || A[i+1] == ']' || A[i+1] == '{' || A[i+1] == '[')
            continue;
            if(A[i+1]==' ')
            {
                i++;
                temp += A[i];
                continue;
            }
            ans.push_back(temp);
            temp = "";
            c = 1;
        }
        else
        {
            if(c)
            {
                for(int j=0;j<space;j++)
                temp += '\t';
                c = 0;
            }
            temp += A[i];
        }
    }
    return ans;
}

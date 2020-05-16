vector<string> Solution::restoreIpAddresses(string A) {
    int n = A.size();
    string num1 = "",num2 = "",num3 = "",num4 = "",temp = "";
    vector<string> ans;
    for(int i=0;i<3 && i<n;i++)
    {
        num1 += A[i];
        if(num1.size()>3 || (num1.size()==3 && num1>"255") || num1.size()>1 && num1[0]=='0')
        break;
        num2 = "";
        for(int j= i+1;j<=i+3 && j<n;j++)
        {
            num2 += A[j];
            if(num2.size()>3 || (num2.size()==3 && num2>"255") || (num2.size()>1 && num2[0]=='0'))
            break;
            num3 = "";
            for(int k = j+1;k<=j+3 && k<n;k++)
            {
                num3 += A[k];
                if(num3.size()>3 || (num3.size()==3 && num3>"255") || (num3.size()>1 && num3[0]=='0'))
                break;
                num4 = "";
                if(n-(k+1)>3)
                continue;
                for(int l=k+1;l<n;l++)
                num4 += A[l];
                if(num4 == "" || num4.size()>3 || (num4.size()==3 && num4>"255") || (num4.size()>1 && num4[0]=='0'))
                continue;
                temp = num1 + '.' + num2 + '.' + num3 + '.' + num4;
                ans.push_back(temp);
                temp = "";
            }
        }
    }
    return ans;
}

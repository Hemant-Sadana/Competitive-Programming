string Solution::multiply(string A, string B) {
    int y1=A.size(),y2=B.size(),i,j,prod=0,carry=0,beg=0,sum=0,k=0;
    string temp="",sol="",sol1="";
    if(A=="0"||B=="0")
    return "0";
    for(i=y2-1;i>=0;i--)
    {
        for(j=y1-1;j>=0;j--)
        {
            prod = (A[j]-48)*(B[i]-48)+carry;
            carry = prod/10;
            prod = prod%10;
            temp+=(prod+48);
        }
        if(carry!=0)
        temp+=(carry+48);
        for(j=0;j<beg;j++)
        sol1+=sol[j];
        k=0;carry=0;
        for(j=beg;j<sol.size();j++)
        {
            sum = (sol[j]-48)+(temp[k]-48)+carry;
            carry = sum/10;
            sum=sum%10;
            sol1+=(sum+48);
            k++;
        }
        for(j=k;j<temp.size();j++)
        {
            sum = (temp[j]-48)+carry;
            carry=sum/10;
            sum=sum%10;
            sol1+=(sum+48);
        }
        if(carry!=0)
        sol1+=(carry+48);
        sol=sol1;
        sol1="";
        temp="";
        carry=0;
        beg++;
    }
    reverse(sol.begin(),sol.end());
    for(i=0;i<sol.size();i++)
    {
        if(sol[i]!='0')
        break;
    }
    for(j=i;j<sol.size();j++)
    temp+=sol[j];
    return temp;
}

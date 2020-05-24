int convert(string temp)
{
    int n = temp.size(),bin = 0,mul = 1;
    for(int i=0;i<n;i++)
    {
        bin = bin + mul*(temp[i]-48);
        mul = mul*2;
    }
    return bin;
}
vector<int> Solution::grayCode(int A) {
    vector<string> temp;
    vector<int> ans;
    temp.push_back("0");
    temp.push_back("1");
    int count = 2,rev = 1;
    A = pow(2,A);
    while(count<A)
    {
        for(int i=rev;i>=0;i--)
        temp.push_back(temp[i]);
        for(int i=0;i<=rev;i++)
        temp[i].push_back('0');
        for(int i=rev+1;i<temp.size();i++)
        temp[i].push_back('1');
        count = count*2;
        rev = temp.size()-1;
    }
    for(int i=0;i<A;i++)
    {
        ans.push_back(convert(temp[i]));
    }
    return ans;
}

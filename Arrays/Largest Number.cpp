bool mysort(string a,string b)
{
    if((a+b)>=(b+a))
    return true;
    return false;
}
string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<string> ans;
    string temp="";
    for(int i=0;i<n;i++)
    ans.push_back(to_string(A[i]));
    sort(ans.begin(),ans.end(),mysort);
    for(int i=0;i<n;i++)
    temp+=ans[i];
    if(temp[0]=='0')
    return "0";
    return temp;
}

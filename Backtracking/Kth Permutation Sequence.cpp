int fact(int n)
{
    int f = 1;
    if(n>12)
    return INT_MAX;
    for(int i=2;i<=n;i++)
    f = f*i;
    return f;
}
string Solution::getPermutation(int A, int B) {
    vector<int> temp;
    string ans="";
    for(int i=1;i<=A;i++)
    temp.push_back(i);
    int f = fact(A-1),index;
    B = B-1;
    for(int i=0;i<A;i++)
    {
        index = B/f;
        B = B%f;
        ans+=to_string(temp[index]);
        temp.erase(temp.begin()+index);
        f = fact(temp.size()-1);
    }
    return ans;
}

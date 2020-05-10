long long int fact(int n)
{
    long long int f=1;
    for(int i=2;i<=n;i++)
    f = (f*i)%1000003;
    return f;
}
int Solution::findRank(string A) {
    int n = A.size(),m;
    string temp="";
    for(int i=0;i<n;i++)
    temp += A[i];
    sort(temp.begin(),temp.end());
    int index = 0,rank = 0;
    for(int i=0;i<n;i++)
    {
        index = temp.find(A[i]);
        m = temp.size();
        rank = (rank + (index*fact(m-1))%1000003)%1000003;
        temp.erase(index,1);
    }
    return (rank+1)%1000003;
}

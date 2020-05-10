string Solution::convertToTitle(int A) {
    string ans = "";
    int x;
    while(A>0)
    {
        x = A%26;
        if(x==0)
        {
            ans = 'Z' + ans;
            A = A-26;
        }
        else
        {
            x = x + 64;
            ans = char(x) + ans;
            A = A - (A%26);
        }
        A = A/26;
    }
    return ans;
}

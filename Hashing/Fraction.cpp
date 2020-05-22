string Solution::fractionToDecimal(int A, int B) {
    string sign = "";
    if(A<0 && B>0 || A>0 && B<0)
    sign = "-";
    long int c,d,a,b,quot,rem;
    c = A;d = B;
    a = abs(c);b = abs(d);
    quot = a/b;rem = a%b;
    if(rem == 0)
    return sign + to_string(quot);
    string ans = to_string(quot) + ".",t = "";
    map<long int,long int> hashi;
    hashi[rem] = 0;
    rem = rem*10;
    int  i = 1,repeat = -1,start = ans.size(); 
    while(rem!=0)
    {
        quot = rem/b;
        ans = ans + to_string(quot);
        rem = rem%b;
        if(hashi.find(rem)!=hashi.end())
        {
            repeat = hashi[rem];
            break;
        }
        hashi[rem] = i;
        i++;
        rem = rem*10;
    }
    if(repeat == -1)
    return sign + ans;
    repeat = repeat + start;
    t = sign + ans.substr(0,repeat) + "(" + ans.substr(repeat) + ")";
    return t;
}

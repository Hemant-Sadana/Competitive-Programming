string Solution::multiple(int A) {
    if(A == 0 || A == 1)
    return to_string(A);
    queue<int> q;
    vector<bool> rem(A,false);
    vector<int> val(A,0);
    vector<int> prev(A,0);
    q.push(1);
    int num,r1,r2,x = 0;
    rem[1] = true;
    val[1] = 1;
    prev[1] = -1;
    while(1)
    {
        num = q.front();
        q.pop();
        r1 = (num*10)%A;
        r2 = (r1+1)%A;
        if(!rem[r1])
        {
            q.push(r1);
            rem[r1] = true;
            val[r1] = 0;
            prev[r1] = num;
            if(r1 == 0)
            {
                break;
            }
        }
        if(!rem[r2])
        {
            q.push(r2);
            rem[r2] = true;
            val[r2] = 1;
            prev[r2] = num;
            if(r2 == 0)
            {
                break;
            }
        }
    }
    string ans = "";
    ans += to_string(val[0]);
    while(prev[x]!=-1)
    {
        ans = to_string(val[prev[x]]) + ans;
        x = prev[x];
    }
    return ans;
}

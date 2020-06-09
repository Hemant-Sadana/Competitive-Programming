int bfs(int A,int B,int C,int D,int E,int F)
{
    vector<vector<int> > dp(A,vector<int> (B,INT_MAX));
    queue<pair<int,int> > q;
    pair<int,int> temp;
    q.push(make_pair(C,D));
    dp[C][D] = 0;
    int x[8] = {-1,-2,-2,-1,1,2,1,2};
    int y[8] = {2,1,-1,-2,2,1,-2,-1};
    int row = A,col = B;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        C = temp.first;
        D = temp.second;
        if(C==E && D==F)
        continue;
        if(dp[C][D]>=dp[E][F])
        continue;
        for(int i=0;i<8;i++)
        {
            if(C+x[i]<0 || C+x[i]>=row || D+y[i]<0 || D+y[i]>=col || dp[C+x[i]][D+y[i]] <= dp[C][D] + 1)
            continue;
            q.push(make_pair(C+x[i],D+y[i]));
            dp[C+x[i]][D+y[i]] = dp[C][D] + 1;
        }
    }
    return (dp[E][F] == INT_MAX) ? -1 : dp[E][F];
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    return bfs(A,B,C-1,D-1,E-1,F-1);
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int> > dp(A+1,vector<int> (B+1,1));
    for(int i=0;i<C;i++)
    {
        for(int j=0;j<=A;j++)
        {
            for(int k=0;k<=B;k++)
            {
                if((j-E[i])*(j-E[i]) + (k-F[i])*(k-F[i])<=D*D)
                dp[j][k] = 0;
            }
        }
    }
    queue<pair<int,int> > q;
    pair<int,int> temp;
    if(dp[0][0] == 0)
    return "NO";
    q.push(make_pair(0,0));
    int x,y;
    int xd[8] = {1,0,-1,0,1,1,-1,-1};
    int yd[8] = {0,1,0,-1,-1,1,1,-1};
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        x = temp.first;
        y = temp.second;
        dp[x][y] = 0;
        if(x==A && y==B)
        return "YES";
        for(int i=0;i<8;i++)
        {
            if(x+xd[i]<0 || x+xd[i]>A || y+yd[i]<0 || y+yd[i]>B || dp[x+xd[i]][y+yd[i]] == 0)
            continue;
            q.push(make_pair(x+xd[i],y+yd[i]));
            dp[x+xd[i]][y+yd[i]] = 0;
        }
    }
    return "NO";
}

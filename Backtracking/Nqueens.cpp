bool safe(vector<string> temp,int row, int col,int A)
{
    for(int i=0;i<A;i++)
    {
        if(temp[row][i]=='Q')
        return false;
        if(temp[i][col] == 'Q')
        return false;
    }
    int a = row,b = col;
    while(a>0 && b>0)
    {
        a--;b--;
    }
    while(a<A && b<A)
    {
        if(temp[a][b] == 'Q')
        return false;
        a++;b++;
    }
    while(row>0 && col<A-1)
    {
        row--;col++;
    }
    while(row<A && col>=0)
    {
        if(temp[row][col]=='Q')
        return false;
        row++;col--;
    }
    return true;
}
void queen(vector<string> temp,int A,int col,vector<vector<string> > &ans)
{
    if(col==A)
    {
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<A;i++)
    {
        if(safe(temp,i,col,A))
        {
            temp[i][col] = 'Q';
            queen(temp,A,col+1,ans);
        }
        temp[i][col] = '.';
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    string t;
    for(int i=0;i<A;i++)
    t+='.';
    vector<string> temp;    
    vector<vector<string> > ans;
    for(int i=0;i<A;i++)
    temp.push_back(t);
    queen(temp,A,0,ans);
    return ans;
}

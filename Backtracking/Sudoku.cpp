int f = 0;
bool safe(vector<vector<char> > &A,int row,int col,char num)
{
    for(int i=0;i<9;i++)
    {
        if(A[row][i]==num)
        return false;
        if(A[i][col]==num)
        return false;
    }
    row = (row/3)*3;col = (col/3)*3;
    for(int i=row;i<row+3;i++)
    {
        for(int j=col;j<col+3;j++)
        {
            if(A[i][j]==num)
            return false;
        }
    }
    return true;
}
void solve(vector<vector<char> > &A,int row,int col)
{
    if(row == 9 || f==1)
    {
        f = 1;
        return;
    }
    if(col==9)
    {
        solve(A,row+1,0);
        return;
    }
    if(A[row][col]=='.')
    {
        for(int i=1;i<=9;i++)
        {
            if(safe(A,row,col,i+48))
            {
                A[row][col] = i+48;
                solve(A,row,col+1);
                if(f!=1)
                A[row][col]='.';
            }
            if(f==1)
            return;
        }
    }
    else
    solve(A,row,col+1);
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    f = 0;
    solve(A,0,0);    
}

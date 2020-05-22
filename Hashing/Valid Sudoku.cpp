bool valid(const vector<string> &A,int row,int col)
{
    map<int,int> hash;
    int re = row+3,ce = col+3;
    for(int i=row;i<re;i++)
    {
        for(int j=col;j<ce;j++)
        {
            if(A[i][j]!='.' && hash.find(A[i][j])!=hash.end())
            return false;
            hash[A[i][j]] = 1;
        }
    }
    return true;
}
int Solution::isValidSudoku(const vector<string> &A) {
    int n = A.size();
    map<int,int> hashr,hashc;
    for(int i=0;i<n;i++)
    {
        hashr.clear();hashc.clear();
        for(int j=0;j<n;j++)
        {
            if(A[i][j]!='.' && hashr.find(A[i][j])!=hashr.end())
            return 0;
            if(A[j][i]!='.' && hashc.find(A[j][i])!=hashc.end())
            return 0;
            hashr[A[i][j]] = 1;hashc[A[j][i]] = 1;
        }
    }
    for(int i=0;i<3;i++)
    {
        if(!valid(A,i*3,0) || !valid(A,i*3,3) || !valid(A,i*3,6))
        return 0;
    }
    return 1;
}

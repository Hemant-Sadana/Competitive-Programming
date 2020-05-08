void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int row = A.size(),col = A[0].size();
    bool rowzero=false,colzero=false;
    for(int i=0;i<col;i++)
    {
        if(A[0][i]==0)
        {
            rowzero = true;
            break;
        }
    }
    for(int i=0;i<row;i++)
    {
        if(A[i][0]==0)
        {
            colzero = true;
            break;
        }
    }
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(A[i][j]==0)
            {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        A[i][j] = A[i][0] && A[0][j];
    }
    if(rowzero)
    {
        for(int i=0;i<col;i++)
        A[0][i] = 0;
    }
    if(colzero)
    {
        for(int i=0;i<row;i++)
        A[i][0] = 0;
    }
    return;
}

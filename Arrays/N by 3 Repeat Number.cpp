int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()<3)
    return A[0];
    int n = A.size(),i,j,e;
    pair<int,int> count[2];
    count[0].first = A[0];
    count[0].second = 1;
    int f1 = 1,f2 = 0;
    for(j=i+1;j<n;j++)
    {
        if(A[j]==count[0].first && f1)
        count[0].second++;
        else if(A[j]==count[1].first && f2)
        count[1].second++;
        else if(f1==0)
        {
            count[0].first = A[j];
            count[0].second = 1;
            f1 = 1;
        }
        else  if(f2==0)
        {
            count[1].first = A[j];
            count[1].second = 1;
            f2 = 1;
        }
        else
        {
            count[0].second--;
            if(count[0].second==0)
            f1 = 0;
            count[1].second--;
            if(count[1].second==0)
            f2 = 0;
        }
    }
    f1 = 0;f2 = 0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==count[0].first)
        f1++;
        else if(A[i]==count[1].first)
        f2++;
    }
    if(f1>n/3)
    return count[0].first;
    if(f2>n/3)
    return count[1].first;
    return -1;
}

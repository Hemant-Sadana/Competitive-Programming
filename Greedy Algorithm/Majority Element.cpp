int Solution::majorityElement(const vector<int> &A) {
    int n = A.size(),maj = 0,c = 1;
    for(int i=1;i<n;i++)
    {
        if(A[i] == A[maj])
        c++;
        else
        {
            c--;
            if(c == 0)
            {
                c = 1;
                maj = i;
            }
        }
    }
    return A[maj];
}

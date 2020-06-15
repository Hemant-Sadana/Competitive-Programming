int Solution::jump(vector<int> &A) {
     if(A.size()<=1)
    return 0;
    int n = A.size(),steps = 1,reach = A[0],curr = A[0];
    for(int i=1;i<n;i++)
    {
        if(reach<i)
        return -1;
        if(i>curr)
        {
            steps++;
            curr = reach;
        }
        if(i+A[i]>reach)
        reach = i+A[i];
    }
    return steps;
}

bool possible(vector<int> &A,int B,int mid)
{
    int sum=0,c=1,n=A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]>mid)
        return false;
        if(sum + A[i]>mid)
        {
            sum = A[i];
            c++;
            if(c>B)
            return false;
        }
        else
        sum+=A[i];
    }
    return true;
}
int Solution::books(vector<int> &A, int B) {
    int n = A.size(),low = 0 ,high = 0,ans = INT_MAX,mid;
    if(B>n)
    return -1;
    for(int i=0;i<n;i++)
    {
        high += A[i];
    }
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(possible(A,B,mid))
        {
            ans = mid;
            high = mid-1;
        }
        else
        low = mid+1;
    }
    return ans;
}

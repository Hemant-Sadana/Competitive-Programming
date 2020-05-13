bool possible(int A,vector<int> &C,int mid)
{
    long int c = 1,sum = 0;
    for(int i=0;i<C.size();i++)
    {
        if(C[i]>mid)
        return false;
        if(sum + C[i]>mid)
        {
            sum = C[i];
            c++;
            if(c>A)
            return false;
        }
        else
        sum += C[i];
    }
    return true;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long int n = C.size(),low = 0,high = 0,ans = INT_MAX,mid;
    for(int i=0;i<n;i++)
    {
        high += C[i];
    }
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(possible(A,C,mid))
        {
            ans = mid;
            high = mid-1;
        }
        else
        low = mid+1;
    }
    return (ans*B)%10000003;
}

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n = A.size(),a,b,c,ans = INT_MAX,i,j,k;
    for(i=0;i<n-2;i++)
    {
        if(i!=0 && A[i]==A[i-1])
        continue;
        a = A[i];
        j = i+1;k = n-1;
        while(j<k)
        {
            b = A[j];c = A[k];
            ans = min(ans,abs(B-(a+b+c)));
            if(a+b+c>B)
            k--;
            else if(a+b+c<B)
            j++;
            else return B;
        }
    }
    return B - ans;
}

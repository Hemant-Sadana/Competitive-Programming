vector<vector<int> > Solution::threeSum(vector<int> &A) {
    int n = A.size(),i,j,k,prev,sum;
    sort(A.begin(),A.end());
    vector<vector<int> > sol;
    for(i=0;i<n-2;i++)
    {
        if(i!=0 && A[i]==A[i-1])
        continue;
        j=i+1;
        k=n-1;
        while(j<k)
        {
            sum = A[i]+A[j]+A[k];
            if(sum==0)
            {
                vector<int> temp;
                temp.push_back(A[i]);
                temp.push_back(A[j]);
                temp.push_back(A[k]);
                sol.push_back(temp);
                prev = A[j];
                j++;
                k--;
                while(A[j]==prev && j<k)
                j++;
                
            }
            else if(sum>0)
            k--;
            else
            j++;
        }
    }
    return sol;
}

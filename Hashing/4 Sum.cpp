vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int k,l,sum,n = A.size();
    vector<vector<int> > ans;
    vector<int> temp;
    for(int i=0;i<n-3;i++)
    {
        if(i!=0 && A[i]==A[i-1])
        continue;
        for(int j=i+1;j<n-2;j++)
        {
            if(j!=i+1 && A[j]==A[j-1])
            continue;
            k = j+1;l = n-1;
            while(k<l)
            {
               sum = A[i] + A[j] + A[k] + A[l];
               if(sum>B)
               l--;
               else if (sum<B)
               k++;
               else
               {
                   temp.push_back(A[i]);temp.push_back(A[j]);
                   temp.push_back(A[k]);temp.push_back(A[l]);
                   ans.push_back(temp);
                   temp.clear();
                   k++;l--;
                   while(k<l && A[k]==A[k-1])
                   k++;
                   while(k<l && A[l]==A[l+1])
                   l--;
               }
            }
        }
    }
    return ans;
}

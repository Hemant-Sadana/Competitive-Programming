int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size(),zs = 0,max_slope = 1;
    if(n<=1)
    return n;
    double y2,y1,x2,x1,slope;
    map<double,int> hash;
    for(int i=0;i<n;i++)
    {
        hash.clear();zs = 0;
        for(int j=0;j<n;j++)
        {
            if(i==j)
            continue;
            y2 = B[j];y1 = B[i];x2 = A[j];x1 = A[i];
            if(x1 == x2)
            zs++;
            else
            {
                slope = (y2-y1)/(x2-x1);
                if(hash.find(slope) == hash.end())
                hash[slope] = 1;
                else
                {
                    hash[slope]++;
                }
            }
            max_slope = max(max(hash[slope],max_slope),zs);
        }
    }
    return max_slope+1;
}

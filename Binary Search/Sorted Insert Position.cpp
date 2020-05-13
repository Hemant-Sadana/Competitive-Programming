int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size(),low = 0,high = n-1,mid;    
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(A[mid]==B)
        return mid;
        if(A[mid]>B)
        high = mid-1;
        else
        low = mid+1;
    }
    return low;
}

unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0,j = 31;
    while(i<j)
    {
        if((A&(1<<i)) && !(A&(1<<j)) || !(A&(1<<i)) && (A&(1<<j)))
        {
            A = A ^ (1<<i);
            A = A ^ (1<<j);
        }
        i++;
        j--;
    }
    return A;
}

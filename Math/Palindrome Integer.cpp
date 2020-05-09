int Solution::isPalindrome(int A) {
    int temp = A,rev=0;
    while(temp>0)
    {
        rev = rev*10 + (temp%10);
        temp = temp/10;
    }
    return rev == A;
}

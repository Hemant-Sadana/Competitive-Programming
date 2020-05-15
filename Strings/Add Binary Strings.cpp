string Solution::addBinary(string A, string B) {
    int y1 = A.size(),y2 = B.size(),sum = 0,carry = 0;
    string temp="";
    char ans;
    if(y1<y2)
    {
        swap(A,B);swap(y1,y2);
    }
    int i = y1-1,j = y2-1;
    while(j>=0)
    {
        sum = ((A[i]-48) + (B[j]-48) + carry)%2;
        carry = ((A[i]-48) + (B[j]-48) + carry)/2;
        ans = sum + 48;
        temp = ans + temp;
        i--;j--;
    }
    while(i>=0)
    {
        sum = ((A[i]-48) + carry)%2;
        carry = ((A[i]-48) + carry)/2;
        ans = sum + 48;
        temp = ans + temp;
        i--;
    }
    if(carry == 1)
    temp =  '1' + temp;
    return temp;
}

int Solution::romanToInt(string A) {
    int n = A.size();
    map<char,int> hash;
    hash['I'] = 1;hash['V'] = 5;hash['X'] = 10;hash['L'] = 50;hash['C'] = 100;
    hash['D'] = 500;hash['M'] = 1000;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        if(i==n || hash[A[i]]>=hash[A[i+1]])
        sum = sum + hash[A[i]];
        else
        sum = sum - hash[A[i]];
    }
    return sum;
}

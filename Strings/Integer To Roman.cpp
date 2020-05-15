string Solution::intToRoman(int A) {
    vector<string> M = {"","M","MM","MMM"};
    vector<string> C = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    vector<string> X = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    vector<string> I = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    return M[A/1000] + C[(A%1000)/100] + X[((A%1000)%100)/10] + I[(((A%1000)%100)%10)];
}

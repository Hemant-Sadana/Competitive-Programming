vector<string> Solution::fullJustify(vector<string> &A, int B) {
    int n = A.size(),beg = 0,count = 0,truecount = 0,s = 0,i;
    float spaces = 0;
    vector<string> ans;
    string temp = "";
    while(beg<n)
    {
        count = 0;truecount = 0;spaces = 0;temp = "";s = 0;
        for(i = beg;i<n;i++)
        {
            count = count + A[i].size()+1;
            if(count>B+1)
            break;
            truecount = truecount + A[i].size();
        }
        if(i==n)
        {
            for(int j = beg;j<n-1;j++)
            temp = temp + A[j] + ' ';
            temp += A[n-1];
            while(temp.size()<B)
            {
                temp = temp + ' ';
            }
            ans.push_back(temp);
            break;
        }
        spaces = B-truecount;
        for(int j = beg;j<i;j++)
        {
            temp += A[j];
            s = ceil(spaces/(i-j-1));
            spaces = spaces - s;
            for(int k = 0;k<s;k++)
            temp += ' ';
        }
        while(temp.size()<B)
        temp += ' ';
        ans.push_back(temp);
        beg = i;
    }
    return ans;
}

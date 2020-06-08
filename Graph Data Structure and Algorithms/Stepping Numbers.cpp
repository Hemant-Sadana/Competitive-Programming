vector<int> Solution::stepnum(int A, int B) {
    vector<int> temp,ans;
    for(int i=0;i<10;i++)
    temp.push_back(i);
    int i = 1,n,d;
    while(1)
    {
        d = temp[i]%10;
        if(d-1!=-1)
        {
            if(temp[i]*10 + (d-1)>B)
            break;
            temp.push_back(temp[i]*10 + (d-1));
        }
        if(d+1!=10)
        {
            if(temp[i]*10 + (d+1)>B)
            break;
            temp.push_back(temp[i]*10 + (d+1));
        }
        i++;
        
    }
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i]>=A)
        ans.push_back(temp[i]);
    }
    return ans;
}

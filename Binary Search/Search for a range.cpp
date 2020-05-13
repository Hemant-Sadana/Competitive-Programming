vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size(),low = 0,high = n-1,mid;
    vector<int> ans;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(A[mid]==B)
        break;
        if(A[mid]>B)
        high = mid-1;
        else
        low = mid+1;
    }
    if(A[mid]!=B)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    int start = mid;
    low = 0;high = start;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(mid!=0 && A[mid] == B && A[mid-1]!=B)
        break;
        if(A[mid]<B)
        low = mid+1;
        else
        high = mid-1;
    }
    ans.push_back(mid);
    low = start;high = n-1;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(mid!=n-1 && A[mid]==B && A[mid+1]>B)
        break;
        if(A[mid]>B)
        high = mid-1;
        else 
        low = mid+1;
    }
    ans.push_back(mid);
    return ans;
}

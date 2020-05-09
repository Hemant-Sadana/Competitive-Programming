/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool mysort(Interval a,Interval b)
{
    return (a.start<=b.start) ? true : false;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end(),mysort);
    vector<Interval> ans;
    int s = A[0].start,e = A[0].end;
    for(int i=1;i<A.size();i++)
    {
        if(e<A[i].start)
        {
            ans.push_back(Interval(s,e));
            s = A[i].start;
            e = A[i].end;
        }
        else
        e = max(e,A[i].end);
    }
    ans.push_back(Interval(s,e));
    return ans;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = intervals.size(),f = 1,s = newInterval.start,e = newInterval.end,i,j;
    s = min(s,e);
    e = max(s,e);
    vector<Interval> ans;
    Interval temp; 
    for(i=0;i<n;i++)
    {
        if(s<intervals[i].start)
        {
            f=0;
            temp.start = s;
            break;
        }
        else if(s>=intervals[i].start && s<=intervals[i].end)
        {
            f = 0;
            temp.start = intervals[i].start;
            e = max(e,intervals[i].end);
            break;
        }
        else
        ans.push_back(intervals[i]);
    }
    if(f==1)
    {
        temp.start = s;
        temp.end = e;
        ans.push_back(temp);
        return ans;
    }
    f = 1;
    if(e<intervals[i].start)
    {
        temp.end = e;
        ans.push_back(temp);
        ans.push_back(intervals[i]);
        f = 0;
    }
    else
    e = max(e,intervals[i].end);
    for(int j=i+1;j<n;j++)
    {
        if(e<intervals[j].start && f == 1)
        {
            temp.end = e;
            ans.push_back(temp);
            ans.push_back(intervals[j]);
            f = 0;
        }
        else if(f==1)
        e = max(e,intervals[j].end);
        else
        ans.push_back(intervals[j]);
    }
    if(f==1)
    {
        temp.end = e;
        ans.push_back(temp);
    }
    return ans;
}

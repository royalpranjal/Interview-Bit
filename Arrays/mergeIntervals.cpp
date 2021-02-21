#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool comp(Interval i1,Interval i2){
    if(i1.start<i2.start){
        return true;
    }
    return false;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,n,e,s;
    intervals.push_back(newInterval);
    sort(intervals.begin(),intervals.end(),comp);
    stack<Interval>st;
    st.push(intervals[0]);
    n=intervals.size();
    for(i=1;i<n;i++){
        Interval t=st.top();
        if(t.end>=intervals[i].start){
            st.pop();
            Interval in;
            in.start=t.start;
            in.end=max(t.end,intervals[i].end);
            st.push(in);
        }
        else{
            st.push(intervals[i]);
        }
    }
    intervals.clear();
    while(!st.empty()){
        Interval in=st.top();
        intervals.push_back(in);
        st.pop();
    }
    sort(intervals.begin(),intervals.end(),comp);
    return intervals;
}

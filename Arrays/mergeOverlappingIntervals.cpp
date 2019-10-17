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
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,n=A.size();
    pair<int,int>p[n];
    for(i=0;i<n;i++){
        p[i]=make_pair(A[i].start,A[i].end);
    }
    sort(p,p+n);
        stack<pair<int,int>>s;
        s.push(p[0]);
        for(i=1;i<n;i++){
            if(s.top().second<p[i].first){
                s.push(p[i]);
            }
            else{
                if(p[i].second>s.top().second){
                    pair<int,int>t=s.top();
                    s.pop();
                    t.second=p[i].second;
                    s.push(t);
                }
            }
        }
        vector<pair<int,int>>v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        sort(v.begin(),v.end());
        int m=v.size();
        A.clear();
        for(i=0;i<m;i++){
            Interval ine;
            ine.start=v[i].first;
            ine.end=v[i].second;
            A.push_back(ine);
        }
        return A;
}

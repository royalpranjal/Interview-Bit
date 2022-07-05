// https://www.interviewbit.com/problems/disjoint-intervals/

bool sortCol(const vector<int>&a,const vector<int>&b){
    return a[1]<b[1];
}
int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end(),sortCol);
    int count=1,j=0;
    for(int i=1;i<A.size();i++){
        if(A[j][1]<A[i][0]){
            count++;
            j=i;
        }
    }
    return count;
}
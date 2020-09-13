int Solution::maxp3(vector<int> &A) {
     sort(A.begin(), A.end());
    int n = A.size();
    int all_pos = A[n-3]*A[n-2]*A[n-1]; //can be all negative
    int pos_neg = A[0]*A[1]*A[n-1];     // if 2nd last el is negative
    return max(all_pos, pos_neg);
}

// Credit: dthoang(InterviewBit UserName)
// This Solution is Slightly modified version
int find_less(vector<int> &A, int B, int &C) {
    int head = 0, tail = A.size()-1;
    
    // shortcuts because A is sorted
    if (B > A[tail])
        return tail+1;
    if (B <= A[head]) {
        C = min(C, A[head]);
        return 0;
    }
    // if shortcut failed then
    // binary search
    while (head < tail) {
        int mid = (head + tail) / 2;
        if (B <= A[mid]) {
            tail = mid - 1;
        } else {
            head = mid + 1;
        }
    }
    // make sure we count the number of items strictly less than B
    if (A[head] < B)
        head++;
    
    // get the smallest element greater than B
    if (head < A.size()) {
        C = min(C, A[head]);
    }
    return head;
}

int find_less_matrix(vector<vector<int> > &A, int B, int &C) {
    int less = 0;
    C = INT_MAX;
    for (int i=0;i<A.size();i++) {
        less += find_less(A[i], B, C);
    }
    return less;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int N       = A.size(),M = A[0].size();
    int head    = INT_MAX,tail = INT_MIN;
    int target  = (N*M)/2, actual,result;

    // find min and max elements of A    
    for (int i=0;i<N;i++) {
        head = min(head, A[i][0]);
        tail = max(tail, A[i][M-1]);
    }
    
    // binary search for the median number
    result = head;
    while (head <= tail) {
        int mid = (head + tail) / 2;
        int less = find_less_matrix(A, mid, actual);
        if (target == less) {
            result = actual;
            break;
        }
        if (target < less) {
            tail = mid - 1;
        }
        else {
            result = actual;
            head = mid + 1;
        }
    }
    return result;
}
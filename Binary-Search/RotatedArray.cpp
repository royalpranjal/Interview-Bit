// https://www.interviewbit.com/problems/rotated-array/

int binarySearch(const vector<int> &A){
    int start = 0;
    int end = A.size()-1;
    int mid;
    int n = A.size();
    while(start <= end){
        mid = start + (end-start)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if(A[start] <= A[end]){
            return A[start];
        }
        else if((A[mid] <= A[prev]) && (A[mid] <= A[next])){
            return A[mid];
        }
        else if(A[mid] <= A[end]){
            end = mid-1;
        }
        else{  // A[mid] >= A[start]
            start = mid+1;
        }
    }
    return -1;
}

int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return binarySearch(A);
}

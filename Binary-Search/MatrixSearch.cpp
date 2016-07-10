// https://www.interviewbit.com/problems/matrix-search/

int binarySearch(vector<int> A, int start, int end, int key){
    int mid = start + (end-start)/2;
    if(start <= end){
        if(A[mid] == key){
            return 1;
        }
        else if(A[mid] > key){
            return binarySearch(A, start, mid-1, key);
        }
        else{  // A[mid] < key
            return binarySearch(A, mid+1, end, key);
        }
    }
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int rows = A.size();
    int cols = A[0].size();
    
    for(int i = 0; i < rows; i++){
        if((A[i][0] <= B) && (A[i][cols-1] >= B)){
            if(binarySearch(A[i], 0, cols-1, B)){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
    
    return 0;
}

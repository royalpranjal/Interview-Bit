// https://www.interviewbit.com/problems/count-element-occurence/

int binarySearch(const vector<int> &A, int start, int end, int key, bool searchFirst){
    int result = -1;
    int mid;
    while(start <= end){
        mid = start + (end-start)/2;
        if(A[mid] == key){
            result = mid;
            if(searchFirst){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }    
        else if(A[mid] < key){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return result;
}

int Solution::findCount(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if((binarySearch(A, 0, A.size()-1, B, true)) == -1){
        return 0;
    }
    return (binarySearch(A, 0, A.size()-1, B, false)) - (binarySearch(A, 0, A.size()-1, B, true)) + 1;
}

// https://www.interviewbit.com/problems/square-root-of-integer/

int binarySearch(int A, int start, int end){
    int mid = floor(start + (end-start)/2);
    if(start <= end){
        if(mid <= (A/mid) && (mid+1) > (A/(mid+1))){
            return mid;         
        }
        else if( mid < (A/mid) ){
            start = mid+1;
            return binarySearch(A, mid+1, end);
        }
        else if( mid > (A/mid) ){ // mid*mid > A
            end = mid-1;
            return binarySearch(A, start, end);
        }
    }
    
    return mid;
}

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A == 0){
        return 0;
    }
    else if(A == 1){
        return 1;
    }
    else{
        return binarySearch(A, 0, A);
    }
        
}

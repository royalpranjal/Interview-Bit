// https://www.interviewbit.com/problems/sorted-insert-position/

int binary(int lower, int upper, int key, vector<int> &A){
    int mid = (upper+lower)/2;
    
    if(lower <= upper){
        if(key > A[mid]){
            lower = mid+1;
            return binary(lower, upper, key, A);
        }
        else if(key < A[mid]){
            upper = mid-1;
            return binary(lower, upper, key, A);
        }    
    }
    else{
        if(key == A[mid]){
            return mid;
        }
        else if(key > A[mid]){
            return mid+1;
        }
        else if(key < A[mid]){
            return mid;
        }
    }
    return mid;     
}

int Solution::searchInsert(vector<int> &A, int B) {
    int upper, lower, key, position = 0;
    
    lower = 0;
    upper = A.size()-1;
    key = B;
    
    if(A[upper] < key){
        return A.size();
    }    
    else if(A[0] > key){
        return 0;
    }
    else{
        position = binary(lower, upper, key, A);
    }
    return position;
}

// https://www.interviewbit.com/problems/rotated-sorted-array-search/

int search1(const vector<int> &arr, int low, int high, int B) 
{ 
    if (low > high) return -1; 
  
    int mid = (low) + (high-low)/2; 
    if (arr[mid] == B) return mid; 
  
    if (arr[low] <= arr[mid]) 
    { 
        if (B >= arr[low] && B <= arr[mid]) 
        return search1(arr, low, mid-1, B); 

        return search1(arr, mid+1, high, B); 
    } 
  
    else if (arr[mid] <= arr[high])
    {
    if (B >= arr[mid] && B <= arr[high]) 
        return search1(arr, mid+1, high, B); 
  
    return search1(arr, low, mid-1, B); 
    }
} 


int Solution::search(const vector<int> &A, int B) {
    
   int n = A.size();
   int i = search1(A, 0, n-1, B); 
  
    if (i != -1) 
    return i;
    else
    return -1;
    
}

/*
int findPivot(const vector<int> &A){
    int start = 0;
    int end = A.size()-1;
    int mid;
    int n = A.size();
    while(start <= end){
        mid = start + (end-start)/2;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(A[start] <= A[end]){
            return start;
        }
        else if((A[mid] <= A[prev]) && (A[mid] <= A[next])){
            return mid;
        }
        else if(A[mid] <= A[end]){
            end = mid-1;
        }
        else{ // A[mid] >= A[start]
            start = mid+1;
        }
    }
    return -1;
}

int binarySearch(const vector<int> &A, int start, int end, int key){
    int mid;
    while(start <= end){
        mid = start + (end-start)/2;
        if(A[mid] == key){
            return mid;
        }
        else if(A[mid] > key){
            end = mid-1;
        }
        else{ // A[mid] < key
            start = mid+1;
        }
    }
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int pivot = findPivot(A);
    if(B == A[pivot]){
        return pivot;
    }
    
    int result = binarySearch(A, 0, pivot-1, B);
    
    if(result == -1){
        return binarySearch(A, pivot+1, A.size()-1, B);    
    }
    
    return result;
    
    // B < A[pivot]
    
}
*/

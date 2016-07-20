// https://www.interviewbit.com/problems/remove-element-from-array/

// void swap(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

int Solution::removeElement(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i = 0;
    int length = A.size();
    
    while(i < A.size()){
        if(A[i] == B){
            break;
        }
        i++;
    }
    
    if(i == length){
        return length;
    }
    
    int j = i+1;
    
    while(j < length){
        if(A[j] != B){
            A[i] = A[j];
            i++;
        }
        j++;
    }
    
    while(i < length){
        A.pop_back();
        i++;
    }
    
    return A.size();
    
}

// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int length = A.size();
    int i = 0;
    
    if(length == 0){
        return length;
    }
    
    int curr = A[0];
    int count = 0;
    
    while(i < length){
        if(A[i] == curr){
            count++;
            if(count == 3){
                break;
            }
        }
        else{
            count = 1;
            curr = A[i];
        }
        i++;
    }
    
    int j = i+1;
    while(j < length){
        if(A[j] != curr){
            A[i] = A[j];
            curr = A[i];
            count = 1;
            i++;
        }
        else{
            if(count < 2){
                A[i] = A[j];
                i++;**
            }
            count++;
        }
        j++;
    }
    
    while(i < length){
        A.pop_back();
        i++;
    }
    
    return A.size();
    
}

// https://www.interviewbit.com/problems/first-missing-integer/

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

bool checkCorrect(int A, int index){
    if((A-1) == index){
        return true;
    }
    return false;
}

void makeCorrect(vector<int>& A, int index){
    if(A[index] < A.size()){
        if(A[A[index]-1] != A[index]){
            swap(A[A[index]-1], A[index]);
            if(A[index] > 0){
                bool a = checkCorrect(A[index], index);
                if(a == false){
                    makeCorrect(A, index);
                }
            }
        }
    }
}

int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool check;
    for(int i = 0; i < A.size(); i++){
        if(A[i] > 0){
            check = checkCorrect(A[i], i);
            if(check == false){
                makeCorrect(A, i);  
            }
        }
    }
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] != (i+1)){
            return i+1;
        }
    }
    return A.size()+1;
}

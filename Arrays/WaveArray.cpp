// https://www.interviewbit.com/problems/wave-array/

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

vector<int> Solution::wave(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end());
    int size = A.size();
    if(A.size()%2 != 0){
        size = A.size()-1;
    }
    for(int i = 0; i < size; i=i+2){
        swap(A[i],A[i+1]);
    }
    
    return A;
}

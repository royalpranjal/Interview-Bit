// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

bool checkGreater(int A, int B){
    if(A > B){
        return true;
    }
    return false;
}

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0, j = 0;
    while((i < A.size()) && (j < B.size())){
        bool a = checkGreater(A[i], B[j]);
        if(a){
            A.insert(A.begin()+i, B[j]);
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    while(j != B.size()){
        A.push_back(B[j]);
        j++;
    }
}

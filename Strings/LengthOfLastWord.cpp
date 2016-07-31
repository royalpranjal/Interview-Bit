// https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int length = 0;
    for(int i = A.size()-1 ; i >=0; i--){
        char c = A[i];
        if(isspace(c)){
            if(length != 0){
                return length;
            }
            else{
                length = 0;    
            }
        }
        else{
            length++;    
        }
    }
    
    return length;
}

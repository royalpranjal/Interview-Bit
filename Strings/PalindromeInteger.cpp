// https://www.interviewbit.com/problems/palindrome-integer/

bool Solution::isPalindrome(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stringstream ss;
    
    while(A){
        ss << A%10;
        A = A/10;
    }
    
    string B = ss.str();
    
    for(int i = 0; i < B.size()/2; i++){
        if(B[i] != B[B.size()-i-1]){
            return false;
        }
    }
    
    return true;
}

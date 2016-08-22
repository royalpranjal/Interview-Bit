// https://www.interviewbit.com/problems/binary-representation/

string Solution::findDigitsInBinary(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    stringstream ss;
    
    if(A == 0){
        return "0";
    }
    
    while(A){
        ss << A%2;
        A = A/2;
    }
    
    string ans = ss.str();
    
    for(int i = 0; i < ans.size()/2; i++){
        char temp = ans[i];
        ans[i] = ans[ans.size()-1-i];
        ans[ans.size()-1-i] = temp;
    }
    
    return ans;
    
}

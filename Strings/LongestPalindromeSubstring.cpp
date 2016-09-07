// https://www.interviewbit.com/problems/longest-palindromic-substring/

string Solution::longestPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int start = 0;
    int length = A.size();
    int maxLen = 1;
    
    int low = 0, high;
    
    for(int i = 0; i < length; i++){
        low = i-1;
        high = i;
        while((low >= 0) && (high < length) && (A[low] == A[high])){
            if((high - low + 1) > maxLen){
                maxLen = high-low+1;
                start = low;
            }        
            low--;
            high++;
        }
        
        low = i-1;
        high = i+1;
        while((low >= 0) && (high < length) && A[low] == A[high]){
            if((high - low + 1) > maxLen){
                maxLen = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
    }
    
    string sol = "";
    
    high = start+maxLen;
    while(start != high){
        sol = sol + A[start];
        start++;
    }
    
    return sol;
}

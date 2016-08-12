// https://www.interviewbit.com/problems/longest-substring-without-repeat/

int Solution::lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    unordered_map<char, int> myMap;
    int temp = 0, sol = 0, i = 0, j = 0;
    
    while(j < A.size()){
        if(myMap.find(A[j]) == myMap.end()){
            myMap[A[j]] = 1;
            j++;
            temp++;
        }
        else{
            while(A[i] != A[j]){
                myMap.erase(A[i]);
                i++;
                temp--;
            }  
            if(i != j){
                i++;    
            }
            temp--;
            myMap.erase(A[j]);
        }
        if(temp > sol){
            sol = temp;
        }
    }
    return sol;
}

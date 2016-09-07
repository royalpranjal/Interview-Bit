// https://www.interviewbit.com/problems/palindrome-string/

int Solution::isPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0;
    int j = A.size()-1;
    
    LOOP:while(i < j){
        char c = A[i];
        char d = A[j];
        if(!
            (
                (  
                    (
                        (int)c >= 97
                    )
                    && 
                    (
                        (int)c <= 122
                    )  
                ) 
                || 
                ( 
                    ( 
                        (int)c >= 65
                    ) 
                    && 
                    ( 
                        (int)c <= 90
                    )
                ) 
                ||
                (
                    isdigit(c)
                )
            )
        )
        {
            
            
            i++;
            goto LOOP;
        }
        if(!
            (
                (  
                    (
                        (int)d >= 97
                    )
                    && 
                    (
                        (int)d <= 122
                    )  
                ) 
                || 
                ( 
                    ( 
                        (int)d >= 65
                    ) 
                    && 
                    ( 
                        (int)d <= 90
                    )
                )
                ||
                (
                    isdigit(d)
                )
            )
        ){
            j--;
            goto LOOP;
        }
        c = tolower(c);
        d = tolower(d);
        if(c != d){
            return 0;
        }
        i++;
        j--;
    }
    
    return 1;
}

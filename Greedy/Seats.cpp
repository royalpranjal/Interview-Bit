// https://www.interviewbit.com/problems/seats/

int Solution::seats(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int count = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] == 'x'){
            count++;
        }
    }
    
    if(count == 0 || count == 1){
        return 0;
    }
    
    int mid = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] == 'x'){
            mid++;
            if(mid == (count/2)+1){
                mid = i;
                break;
            }
        }
    }
    
    long long int i = 0, j = A.size()-1, l = mid-1, r = mid+1;
    long long int sol = 0;
    
    while(i < l || j > r){
        LOO:if(i < l){
            if(A[i] == 'x'){
                if(A[l] == 'x'){
                    l--;
                    goto LOO;
                }
                sol = sol + l - i;
                sol = sol%10000003;
                char temp = A[i];
                A[i] = A[l];
                A[l] = temp;
                l--;
            }
        }
        LOOP:if(j > r){
            if(A[j] == 'x'){
                if(A[r] == 'x'){
                    r++;
                    goto LOOP;
                }
                sol = sol - r + j;
                sol = sol%10000003;
                char temp = A[j];
                A[j] = A[r];
                A[r] = temp;
                r++;
            }        
        }
        j--;
        i++;
    }
    
    // for(int i = 0; i < A.size(); i++){
    //     cout << A[i];
    // }
    
    return (int)(sol%10000003);
}

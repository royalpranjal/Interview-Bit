// https://www.interviewbit.com/problems/max-non-negative-subarray/

vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    long int maxSoFar = 0, overallMax = 0;
    int i = 0, check = 0, j1, j2, negat_count = 0;
    int temp_starting = 0, temp_final = 0, overall_starting = 0, overall_final = 0;
    // vector<int> ans;
    
    LOOP:while(i != A.size()){
        if(A[i] < 0){
            check = 0;
            i++;
            maxSoFar = 0;
            negat_count++;
            goto LOOP;
        }
        check++;
        if(check == 1){
            temp_starting = i;
        }
        temp_final = i;
        maxSoFar = maxSoFar + A[i];
        if(overallMax < maxSoFar){
            overallMax = maxSoFar;
            overall_starting = temp_starting;
            overall_final = temp_final;
        }       
        else if(overallMax == maxSoFar){
            int overall_diff = overall_final-overall_starting;
            int temp_diff = temp_final-temp_starting;
            if(overall_diff == temp_diff){
                // check upto which it is equal
                j1 = temp_starting;
                j2 = overall_starting;
                while(j1 <= temp_final){
                    if(A[j1] < A[j2]){
                        overall_starting = temp_starting;
                        overall_final = temp_final; 
                        break;
                    }
                    else if(A[j1] > A[j2]){
                        break;
                    }
                    else{
                        j1++;
                        j2++;
                    }
                }
            }
            else if(temp_diff > overall_diff){
                overall_starting = temp_starting;
                overall_final = temp_final;
            }
        }
        i++;
    }
    
    vector<int> sol;
    
    if(negat_count != A.size()){
       copy(A.begin()+overall_starting, A.begin()+overall_final+1, back_inserter(sol));
    }
    
    return sol;
}

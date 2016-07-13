// https://www.interviewbit.com/problems/excel-column-number/

int Solution::titleToNumber(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int length = A.size();
    int index, solution = 0;
    
    if(length == 0){
        solution = 0;
    }
    else if(length == 1){
        solution =  ((int)A[length-1])%64; 
    }
    else{
        for(index = 0; index < length-1; index++){
            solution = solution + pow(26,index+1);
            solution = solution + (((int)A[index])%64-1)*pow(26, length-index-1);
        }
        solution = solution + (((int)A[length-1])%64);    
    }
    return solution;
}

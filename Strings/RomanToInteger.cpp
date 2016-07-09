// https://www.interviewbit.com/problems/roman-to-integer/

int value(char c){
    if(c == 'I'){
        return 1;
    }
    else if(c == 'V'){
        return 5;
    }
    else if(c == 'X'){
        return 10;
    }
    else if(c == 'L'){
        return 50;
    }
    else if(c == 'C'){
        return 100;
    }
    else if(c == 'D'){
        return 500;
    }
    else{
        return 1000;
    }
}

int Solution::romanToInt(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int sol = 0, last, sec_last;
    for(int i = A.size()-1; i >= 0; i--){
        char c = A[i];
        last = value(A[i]);
        if(i != 0){
            sec_last = value(A[i-1]);
        }
        sol = sol + last;
        if(sec_last < last){
            sol = sol - sec_last;
            i--;
        }
        sec_last = 0;
        last = 0;
    }
    
    return sol;
}

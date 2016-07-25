// https://www.interviewbit.com/problems/modular-expression/

long long int calMod(int A, int B, int C){
    if(B == 0){
        return 1;
    }
    else if(B%2 == 0){
        long long int y = calMod(A, B/2, C);
        return (y*y)%C;
    }
    else{
        return ((A%C)*calMod(A,B-1,C))%C;
    }
}

int Solution::Mod(int A, int B, int C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == 0){
        return 0;
    }
    
    if(calMod(A, B, C) < 0){
        return C+(int)calMod(A, B, C);
    }
    return (int)calMod(A, B, C);
    
}

// https://www.interviewbit.com/problems/power-of-two-integers/

bool Solution::isPower(int A) {
    
    if(A == 1){
        return true;
    }
    
    for(int i = 2; i < 32; i++){
        for(int j = 2; j <= pow(INT_MAX, 1.0/i); j++){
            if(pow(j, i) == A){
                return true;
            }
        }
    }
    return false;
}

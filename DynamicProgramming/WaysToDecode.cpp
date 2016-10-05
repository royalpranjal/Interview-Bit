// https://www.interviewbit.com/problems/ways-to-decode/

int Solution::numDecodings(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0){
        return 0;
    }
    else if(A[0] == '0'){
        return 0;
    }
    else if(A.size() == 1){
        return 1;
    }
    
    vector<int> temp(A.size()+1);
    
    temp[0] = 1;
    temp[1] = 1;
    
    for(int i = 2; i < temp.size(); i++){
        temp[i] = 0;
        
        if(A[i-1] - '0' > 0){
            temp[i] = temp[i-1];
        }
        if(A[i-1] == '0' && A[i-2] > '2'){
            return 0;
        }
        if((A[i-2] - '0' < 2 && A[i-2] - '0' > 0) || (A[i-2] - '0' == 2 && A[i-1] - '0' <= 6)){
            temp[i] = temp[i] + temp[i-2];
        }
    }
    
    return temp[temp.size()-1];
}

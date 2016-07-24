// https://www.interviewbit.com/problems/add-binary-strings/

void swap(char &c, char &d){
    char temp = c;
    c = d;
    d = temp;
}

void rev(string &A){
    for(int i = 0; i < A.size()/2; i++){
        swap(A[i], A[A.size()-1-i]);
    }    
}

string Solution::addBinary(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = A.size()-1;
    int j = B.size()-1;
    int carry = 0;
    int a, b;
    string c, d;
    string sol = "";
    
    while((i >= 0) || (j >= 0)){
        if(i != -1){
            // a = (int)A[i];
            c = A[i];
            a = stoi(c);
        }
        else{
            a = 0;
        }
        if(j != -1){
            // b = (int)B[j];
            d = B[j];
            b = stoi(d);
        }
        else{
            b = 0;
        }
        if((a+b+carry) == 0){
            sol = sol + '0';
            carry = 0;
        }
        else if((a+b+carry) == 1){
            sol = sol + '1';
            carry = 0;
        }
        else if((a+b+carry) == 2){
            sol = sol + '0';
            carry = 1;
        }
        else if((a+b+carry) == 3){
            sol = sol + '1';
            carry = 1;
        }
        if(i != -1){
            i--;    
        }
        if(j != -1){
            j--;    
        }
    }
    
    if(carry == 1){
        sol = sol + '1';
    }
    
    rev(sol);
    
    return sol;
    
}


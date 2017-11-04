int arrMain[7] = {1, 5, 10, 50, 100, 500, 1000}; 
int arr[6] = {4, 9, 40, 90, 400, 900}; 

int next(int num, bool greater){
    if(greater){
        for(int i = 0; i < 7; i++){
            if(arrMain[i] >= num){
                return arrMain[i];
            }
        }
    }
    else{
        for(int i = 6; i >= 0; i--){
            if(arrMain[i] <= num){
                return arrMain[i];
            }
        }
    }
    
    return 1000;
}

int check(int num, int greater){
    for(int i = 0; i < 6; i++){
        if(arr[i] <= num && arrMain[i+1] == greater){
            return arr[i];
        }
    }
    
    return -1;
}

string convert(int num, map<int, string>& m){
    if(num <= 0){
        return "";
    }
    else if(m.find(num) != m.end()){
        return m[num];
    }
    
    int greater = next(num, true);
    int check_result = check(num, greater);
    if(check_result != -1){
        return convert(greater-check_result, m) + m[greater] + convert(num-check_result, m);
    }
    
    int smaller = next(num, false);
    return m[smaller] + convert(num-smaller, m);
}

string Solution::intToRoman(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string ans = "";
    
    map<int, string> m;
    m[1] = "I";
    m[5] = "V";
    m[10] = "X";
    m[50] = "L";
    m[100] = "C";
    m[500] = "D";
    m[1000] = "M";
    
    while(A >= 1000){
        ans += "M";
        A -= 1000;
    }
    
    return ans + convert(A, m);
}

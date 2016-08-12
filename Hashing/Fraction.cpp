// https://www.interviewbit.com/problems/fraction/

string Solution::fractionToDecimal(int numerator, int denominator) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    string sol = "";
    
    long long int num = numerator;
    long long int den = denominator;
    
    bool neg = false;
    
    if(num < 0){
        neg = true;    
        num = 0 - num;
    }
    if(den < 0){
        if(neg){
            neg = false;
        }
        else{
            neg = true;
        }
        den = 0 - den;
    }
    
    unordered_map<int, int> myMap;
    
    long long int initial = num/den;
    
    if(num == 0){
        return "0";
    }
    
    if(neg){
        sol = sol + "-";
    }
    
    sol = sol + to_string(initial);
    
    num = num%den;
    
    if(num == 0){
        return sol;
    }
    
    sol = sol + ".";
    
    bool repeat = false;
    int val;
    while(num != 0 && repeat == false){
        num = num*10;
        if(myMap.find(num) != myMap.end()){
            repeat = true;
            val = myMap[num];
            break;
        }
        else{
            myMap.insert({num, sol.size()});    
        }
        int temp = num/den;
        sol = sol + to_string(temp);
        num = num%den;
    }
    
    if(repeat){
        sol = sol + ")";
        sol.insert(val, "(");
    }
    
    return sol;
}

// https://www.interviewbit.com/problems/count-and-say/

string Solution::countAndSay(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string str = "11";
    int count = 1;
    stringstream ss;
    
    if(A == 1){
        return "1";
    }
    
    while(A != 2){
        count = 1;
        for(int i = 0; i < str.size(); i++){
            if(i+1 != str.size()){
                if(str[i] == str[i+1]){
                    count++;
                }
                else{
                    ss << count << str[i];
                    count = 1;
                }
            }
            else{
                ss << count << str[i];
            }
        }
        str = ss.str();
        ss.str("");
        A--;
    }
    
    return str;
}

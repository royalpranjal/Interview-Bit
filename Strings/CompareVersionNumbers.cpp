// https://www.interviewbit.com/problems/compare-version-numbers/

string extract(int &i, string str){
    if(i >= str.size()){
        return "0";
    }
    int temp = i;
    stringstream ss;
    ss.str("");
    while(str[temp] != '.' && temp < str.size()){
        ss << str[temp];
        temp++;
    }
    i = temp + 1;
    
    return ss.str();
}

string rem(string a){
    int i = 0;
    while(a[i] == '0' && i < a.size()){
        i++;
    }
    
    return a.substr(i);
}

int compareStr(string a, string b, int first){
    
    string A = rem(a);
    string B = rem(b);
    
    if(A.size() > B.size()){
        return 1;
    }
    else if(A.size() < B.size()){
        return -1;
    }
    else{
        for(int i = 0; i < A.size(); i++){
            int numa = A[i];
            int numb = B[i];
            if(numa > numb){
                return 1;
            }
            else if(numa < numb){
                return -1;
            }
        }
    }
    
    return 0;
}

int Solution::compareVersion(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i = 0, j = 0, first = 1;
    
    while(i < A.size() || j < B.size()){
        string numa = extract(i, A);
        string numb = extract(j, B);
        if(compareStr(numa, numb, first) == 1){
            return 1;
        }
        else if(compareStr(numa, numb, first) == -1){
            return -1;
        }
        first = 0;
    }
    
    return 0;
}

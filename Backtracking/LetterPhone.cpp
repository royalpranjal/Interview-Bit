string checkMapping(int A){
    if(A == '0'){
        return "0";
    }
    else if(A == '1'){
        return "1";
    }
    else if(A == '2'){
        return "abc";
    }
    else if(A == '3'){
        return "def";
    }
    else if(A == '4'){
        return "ghi";
    }
    else if(A == '5'){
        return "jkl";
    }
    else if(A == '6'){
        return "mno";
    }
    else if(A == '7'){
        return "pqrs";
    }
    else if(A == '8'){
        return "tuv";
    }
    else if(A == '9'){
        return "wxyz";
    }
    return "";
}

void rec(vector<string> values, vector<string>& sol, string s, int i, int j){
    int size = values.size();
    if(i == values.size()){
        sol.push_back(s);
        return;
    }
    s = s + "1";
    for(; j < values[i].size(); j++){
        s[s.size()-1] = values[i][j];
        rec(values, sol, s, i+1, 0);
    }
}

vector<string> Solution::letterCombinations(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    vector<string> sol;
    vector<string> values;
    
    for(int i = 0; i < A.size(); i++){
        values.push_back(checkMapping(A[i]));
    }
    rec(values, sol, "", 0, 0);
    
    return sol;
    
}

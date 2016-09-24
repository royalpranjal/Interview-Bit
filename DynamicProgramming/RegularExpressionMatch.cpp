// https://www.interviewbit.com/problems/regular-expression-match/

int match(string s, int i, string p, int j){
    
    if(i >= s.size() && j >= p.size()){
        return 1;
    }
    
    if(i == s.size() && j < p.size()){
        for(int t = j; t < p.size(); t++){
            if(p[t] != '*'){
                return 0;
            }
        }
        return 1;
    }
    
    if(s[i] == p[j] || p[j] == '?'){
        return match(s, i+1, p, j+1);
    }
    
    if(p[j] == '*'){
        return max(match(s, i+1, p, j), match(s, i, p, j+1));
    }
    
}

int Solution::isMatch(const string &s, const string &p) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int pat = p.size();
    int str = s.size();
    
    int i = 0, j = 0;
    int iIndex = -1, jIndex = -1;
    
    while(i < str){
        if(s[i] == p[j] || (j < pat && p[j] == '?')){
            i++;
            j++;
        }
        else if(p[j] == '*' && j < pat){
            jIndex = j;
            iIndex = i;
            j++;
        }
        else if(jIndex != -1){
            j = jIndex + 1;
            i = iIndex + 1;
            iIndex++;
        }
        else{
            return 0;
        }
        
    }
    
    while(j < pat && p[j] == '*'){
        j++;
    }
    
    if(j == pat){
        return 1;
    }
    
    return 0;
    
    
    // return match(s, 0, p, 0);
    
    // vector<vector<int> > temp(str+1, vector<int>(pat+1, 0));
    
    // temp[0][0] = 1;
    
    // for(int i = 1; i < temp[0].size(); i++){
    //     if(p[i-1] == '*'){
    //         temp[0][i] = temp[0][i-1];
    //     }
    // }
    
    // for(int i = 1; i < temp.size(); i++){
    //     for(int j = 1; j < temp[i].size(); j++){
    //         if(p[j-1] == s[i-1] || p[j-1] == '?'){
    //             temp[i][j] = temp[i-1][j-1];
    //         }
    //         else if(p[j-1] == '*'){
    //             temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
    //         }
    //     }
    // }
    
    
    
    // return temp[str][pat];
}

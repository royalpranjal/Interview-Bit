// https://www.interviewbit.com/problems/anagrams/

string mySort(string temp){
    vector<int> str;
    for(int i = 0; i < temp.size(); i++){
        str.push_back((int)temp[i]);
    }
    sort(str.begin(), str.end());
    string ans = "";
    for(int i = 0; i < str.size(); i++){
        ans = ans + (char)str[i];
    }
    
    return ans;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > sol;
    unordered_map<string, vector<int> > myMap;
    
    for(int i = 0; i < A.size(); i++){
        string temp = mySort(A[i]);
        myMap[temp].push_back(i+1);
    }
    
    auto it = myMap.begin();
    
    while(it != myMap.end()){
        sol.push_back(it->second);
        it++;
    }

    return sol;
}

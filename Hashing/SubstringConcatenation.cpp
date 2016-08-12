// https://www.interviewbit.com/problems/substring-concatenation/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> sol;
    
    int wsize = B[0].size();
    int lsize = B.size();
    
    if(A.size() == 0 || B.size() == 0){
        return sol;
    }
    
    unordered_map<string, int> myMap;
    
    for(int i = 0; i < B.size(); i++){
        if(myMap.find(B[i]) != myMap.end()){
            myMap[B[i]]++;
        }
        else{
            myMap[B[i]] = 1;
        }
    }
    
    int i = 0;
    
    while((i + wsize*lsize - 1) < A.size()){
        unordered_map<string, int> tempMap;
        int j = 0;
        while(j < A.size()){
            string temp = A.substr(i + j*wsize, wsize);
            if(myMap.find(temp) == myMap.end()){
                break;
            }
            else{
                if(tempMap.find(temp) == tempMap.end()){
                    tempMap[temp] = 1;
                }
                else{
                    tempMap[temp]++;
                }
                if(tempMap[temp] > myMap[temp]){
                    break;
                }
                j++;
            }
            if(j == lsize){
                sol.push_back(i);
            }
        }
        i++;
    }
    
    return sol;
    
}

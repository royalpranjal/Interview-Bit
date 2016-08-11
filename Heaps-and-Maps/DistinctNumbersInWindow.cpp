// https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B) {
    
    vector<int> ans;
    
    if(B > A.size()){
        return ans;
    }
    
    map<int, int> myMap;
    int unique = 0;
    
    for(int i = 0; i < B; i++){
        auto it = myMap.find(A[i]);
        if(it == myMap.end()){
            myMap[A[i]] = 1;
            unique++;
        }
        else{
            it->second++;
        }
    }
    
    ans.push_back(unique);
    
    for(int i = B; i < A.size(); i++){
        auto it = myMap.find(A[i-B]);
        if(it->second == 1){
            myMap.erase(it);
            unique--;
        }
        else{
            it->second--;
        }
        auto temp = myMap.find(A[i]);
        if(temp != myMap.end()){
            temp->second++;
        }
        else{
            myMap[A[i]] = 1;
            unique++;
        }
        ans.push_back(unique);
    }
    
    return ans;
}

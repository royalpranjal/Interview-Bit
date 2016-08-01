// https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

struct Pair{
    int start;
    int end;
};
vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int, Pair> myMap;
    int sum = 0;
    for(int i = 0; i < A.size(); i++){
        sum = sum+A[i];
        if(myMap.find(sum) != myMap.end()){
            myMap[sum].end = i;
        }
        else{
            myMap[sum].start = i;
            myMap[sum].end = -1;
        }
    }
    
    int min = A.size(), max = 0;
    auto it = myMap.begin();
    while(it != myMap.end()){
        if(it->first == 0){
            if(it->second.end != -1){
                max = it->second.end;
            }
            else{
                max = it->second.start;
            }
            min = -1;
        }
        else if(it->second.end != -1){
            if((max-min) < (it->second.end-it->second.start)){
                max = it->second.end;
                min = it->second.start;
            }
            else if(((max-min) == (it->second.end-it->second.start)) &&
                    min > it->second.start){
                max = it->second.end;
                min = it->second.start;
            }
        }
        it++;    
    }
    
    vector<int> sol;
    for(int i = min+1; i <= max; i++){
        sol.push_back(A[i]);
    }
    
    return sol;
}

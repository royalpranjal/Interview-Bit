// https://www.interviewbit.com/problems/longest-consecutive-sequence/

int Solution::longestConsecutive(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<int, bool> myMap;
    
    for(int i = 0; i < A.size(); i++){
        myMap[A[i]] = false;
    }
    
    auto it = myMap.begin();
    
    while(it != myMap.end()){
        int req = it->first - 1;
        if(myMap.find(req) == myMap.end()){
            it->second = true;            
        }
        it++;
    }
    
    int temp = 0, overall = 0;
    
    it = myMap.begin();
    
    while(it != myMap.end()){
        if(it->second == true){
            auto t = it;
            while(t != myMap.end()){
                int te = t->first + 1;
                temp++;
                t = myMap.find(te);
            }
            if(overall < temp){
                overall = temp;
            }
            temp = 0;
        }
        it++;
    }
    
    return overall;
    
}

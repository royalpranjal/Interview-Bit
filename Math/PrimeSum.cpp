// https://www.interviewbit.com/problems/prime-sum/

vector<int> Solution::primesum(int A) {
    
    vector<bool> val;
    vector<int> sol;
    // unordered_map<int, bool> map;
    
    int i;
    
    for(i = 0; i < A; i++){
        val.push_back(true);
    }
    
    for(i = 2; i <= sqrt(A); i++){
        if(val[i] == true){
            for(int j = 2; i*j <= A; j++){
                val[i*j] = false;
            }
        }
    }
    
    for(i = 2; i < A; i++){
        if(val[i] == true){
            if(val[A - i] == true){
                sol.push_back(i);
                sol.push_back(A-i);
                return sol;
            }
        }
    }
    
    // for(int i = 2; i < A; i++){
    //     // map.insert(i, true);
    //     map[i] = true;
    // } 
    
    // for(int i = 2; i <= sqrt(A); i++){
    //     if(map.at(i) == true){
    //         for(int j = 2; i*j <= A; j++){
    //             map[i*j] = false;
    //         }
    //     }
    // }
    
    // for(int i = 2; i < A; i++){
    //     if(map.at(i) == true){
    //         int temp = A - i;
    //         if(map.at(temp) == true){
    //             sol.push_back(i);
    //             sol.push_back(temp);
    //             return sol;
    //         }
    //     }
    // }
    
   return sol;

}

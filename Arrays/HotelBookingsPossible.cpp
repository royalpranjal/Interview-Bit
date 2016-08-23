// https://www.interviewbit.com/problems/hotel-bookings-possible/

bool comp(pair<int, int> j, pair<int, int> i){
    if(i.first > j.first){
        return true;
    }
    else if(i.first == j.first){
        if(i.second > j.second){
            return true;
        }
    }
    return false;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    // vector<pair<int, int> > vec;
    
    // for(int i = 0; i < arrive.size(); i++){
    //     pair<int, int> p(arrive[i], depart[i]);
    //     vec.push_back(p);
    // }
    
    // sort(vec.begin(), vec.end(), comp);
    
    int arr = 0;
    int dep = 0;
    
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    while(arr < arrive.size()){
        K--;
        arr++;
        if(K == 0){
            if(arrive[arr] >= depart[dep]){
                K++;
                dep++;
            }    
        }
        if(K < 0){
            return false;
        }
    }
    // for(int i = 0; i < vec.size(); i++){
    //     cout << "(" << vec[i].first << "," << vec[i].second << ")" << "  ";
    // }
    
    // while(arr < vec.size()){
    //     while(vec[arr].first >= vec[dep].second){
    //         K++;
    //         dep++;
    //     }
    //     K--;
    //     arr++;
    //     if(K < 0){
    //         return false;
    //     }
    // }
    
    return true;
    
}

// https://www.interviewbit.com/problems/2-sum/

struct Temp{
    int required;
    int start;
    int last;
    int count;
};

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<int, Temp> myMap;
    
    for(int i = 0; i < A.size(); i++){
        if(myMap.find(A[i]) == myMap.end()){
            myMap[A[i]].required = B-A[i];
            myMap[A[i]].start = i;
            myMap[A[i]].last = -1;
            myMap[A[i]].count = 1;
        }
        else{
            if(myMap[A[i]].count == 1){
                myMap[A[i]].last = i;
                myMap[A[i]].count = 2;
            }
        }
    }
    
    int temp_init, temp_final, overall_init, overall_final;
    int count = 0;
    
    auto it = myMap.begin();
    while(it != myMap.end()){
        int check = it->second.required;
        if(myMap.find(check) != myMap.end()){
            int i1 = it->second.start;
            int i2 = myMap[check].start;
            if(i1 != i2){
                count++;
            }
            else{
                if(it->second.last != -1){
                    i2 = it->second.last;
                    count++;
                }
            }
            if(i1 < i2){
                temp_init = i1;
                temp_final = i2;
            }
            else if(i1 > i2){
                temp_init = i2;
                temp_final = i1;
            }
            if(count == 1){
                overall_init = temp_init;
                overall_final = temp_final;
            }
            else{
                if(overall_final > temp_final){
                    overall_init = temp_init;
                    overall_final = temp_final;
                }
                else if(overall_final == temp_final){
                    if(overall_init > temp_init){
                        overall_init = temp_init;
                        overall_final = temp_final;
                    }
                }
            }
        }
        it++;
    }
    
    vector<int> sol;
    if(count != 0){
        sol.push_back(overall_init+1);
        sol.push_back(overall_final+1);
    }
    
    return sol;
}

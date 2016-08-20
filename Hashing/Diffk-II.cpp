//  https://www.interviewbit.com/problems/diffk-ii/

int Solution::diffPossible(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<int, int> myMap;
    
    for(int i = 0; i < A.size(); i++){
        if(myMap.find(A[i]) == myMap.end()){
            myMap[A[i]] = 1;
        }
        else{
            myMap[A[i]] = 2;
        }
    }
    
    auto it = myMap.begin();
    
    while(it != myMap.end()){
        int num = it->first-B;
        if(myMap.find(num) != myMap.end()){
            if(myMap.find(num) != it){
                return 1;    
            }
            else{
                if(it->second > 1){
                    return 1;
                }
            }
        }
        it++;
    }
    
    return 0;
}

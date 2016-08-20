// https://www.interviewbit.com/problems/equal/

vector<int> Solution::equal(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map <int, vector<int> > myMap;
    vector<int> sol;
    vector<int> temp;
    
    int count = 0;
    
    for(int i = 0; i < A.size()-1; i++){
        for(int j = i+1; j < A.size(); j++){
            int sum = A[i] + A[j];
            if(myMap.find(sum) == myMap.end()){
                myMap[sum].push_back(i);
                myMap[sum].push_back(j);
            }
            else{
                temp.push_back(myMap[sum][0]);
                temp.push_back(myMap[sum][1]);
                temp.push_back(i);
                temp.push_back(j); 
                for(int a = 0; a < temp.size()-1; a++){
                    for(int b = a+1; b < temp.size(); b++){
                        if(temp[a] == temp[b]){
                            goto COND;
                        }
                    }
                }
                count++;
                if(count == 1){
                    sol = temp;
                }
                else{
                    for(int z = 0; z < sol.size(); z++){
                        if(sol[z] > temp[z]){
                           sol = temp;
                           break;
                        }    
                        else if(sol[z] < temp[z]){
                            break;
                        }
                    }
                }
                COND:temp.erase(temp.begin(), temp.end());
            }
        }
    }
    
    return sol;
}

// https://www.interviewbit.com/problems/3-sum-zero/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > sol;
    
    if(A.size() < 2){
        return sol;
    }
    
    sort(A.begin(), A.end());
    
    int i = 0;
    
    while(i < A.size()-2){
        int j = i+1;
        int k = A.size()-1;
        LOOP:while(j < k){
            int sum = A[i] + A[j] + A[k];
            if(sum == 0){
                vector<int> temp;
                temp.push_back(A[i]);
                temp.push_back(A[j]);
                temp.push_back(A[k]);
                sol.push_back(temp);
                temp.erase(temp.begin(),temp.end());
                while(A[j] == A[j+1]){
                    j++;
                    if(j == A.size()){
                        break;
                    }
                }
                j++;                
            }
            else if(sum > 0){
                while(A[k] == A[k-1]){
                    k--;
                    if(k == 0){
                        break;
                    }
                }
                k--;
            }
            else{
                while(A[j] == A[j+1]){
                    j++;
                    if(j == A.size()){
                        break;
                    }
                }
                j++;
            }
            
        }
        while(A[i+1] == A[i]){
            i++;
            if(i == A.size()-1){
                return sol;
            }
        }
        i++;
    }
    
    return sol;
    
}

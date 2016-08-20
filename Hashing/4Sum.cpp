// https://www.interviewbit.com/problems/4-sum/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0, j = 1;
    int sum, flag = 0;
    vector<vector<int> >sol;
    if(A.size() < 4){
        return sol;
    }
    sort(A.begin(), A.end());
    
    while(i < A.size()-3){
        j = i+1;
        while(j < A.size()-2){
            int num = B - (A[i]+A[j]);
            int k = j+1;
            int l = A.size()-1;
            while(k < l){
                int sum = A[k]+A[l];
                if(sum == num){
                    vector<int> temp;
                    temp.push_back(A[i]);
                    temp.push_back(A[j]);
                    temp.push_back(A[k]);
                    temp.push_back(A[l]);
                    sol.push_back(temp);
                    temp.erase(temp.begin(), temp.end());
                    while(A[k] == A[k+1] && k < A.size()-1){
                        k++;
                    }
                    while(A[l] == A[l-1] && l > 0){
                        l--;
                    }
                    k++;
                    l--;
                }
                else if(sum < num){
                    k++;
                }
                else{
                    l--;
                }
            }
            while(A[j] == A[j+1]){
                j++;
            }
            j++;
        }
        while(A[i] == A[i+1]){
            i++;
        }
        i++;
    }
    
    return sol;
}

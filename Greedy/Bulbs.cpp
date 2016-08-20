// https://www.interviewbit.com/problems/bulbs/

int Solution::bulbs(vector<int> &A) {

    int count = 0;
    int orig = 1;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] == 0){
            if(orig == 1){
                count++;
                orig = 0;
            }
        }
        else{
            if(orig == 0){
                count++;
                orig = 1;
            }
        }
    }
    
    return count;
}

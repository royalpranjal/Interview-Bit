// https://www.interviewbit.com/problems/maximum-consecutive-gap/

int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() < 2){
        return 0;
    }
    
    vector<int> forMin(A.size(), -1);
    vector<int> forMax(A.size(), -1);
    
    int max_dist = 0, mini = INT_MAX, maxi = INT_MIN;
    int gap = 0, bucket = 0, ind = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] < mini){
            mini = A[i];
        }
        if(A[i] > maxi){
            maxi = A[i];
        }
    }
    
    gap = maxi - mini;
    gap = gap/(A.size()-1);
    
    if(gap == 0){
        return maxi - mini;
    }
    
    for(int i = 0; i < A.size(); i++){
        bucket = (int)((A[i] - mini)/gap);
        if(forMin[bucket] < 0){
            forMin[bucket] = A[i];
            forMax[bucket] = A[i];
        }
        else{
            forMin[bucket] = min(A[i], forMin[bucket]);
            forMax[bucket] = max(A[i], forMax[bucket]);
        }
    }
    
    int max_diff = 0;
    
    for(int i = 0; i < forMin.size(); i++){
        if(forMin[i] >= 0){
            max_diff = max(max_diff, forMin[i]-forMax[ind]);
            ind = i;
        }    
    }
    
    return max_diff;
    
}

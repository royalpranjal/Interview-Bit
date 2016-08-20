// https://www.interviewbit.com/problems/highest-product/

int Solution::maxp3(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() < 3){
        return 0;
    }
    
    long long int neg1 = INT_MAX, neg2 = INT_MAX;
    int neg1_count = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] < neg1 && A[i] < 0){
            neg1_count = 1;
            neg1 = A[i];
        }
        else if(A[i] == neg1 && A[i] < 0){
            neg1_count++;
        }
    }
    
    if(neg1_count > 1){
        neg2 = neg1;
    }
    else if(neg1_count == 1){
        for(int i = 0; i < A.size(); i++){
            if(A[i] < 0 && A[i] < neg2 && neg1 < A[i]){
                neg2 = A[i];
            }
        }
    }
    
    long long int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int max1_count = 0, max2_count = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] > max1){
            max1 = A[i];
            max1_count = 1;
        }
        else if(A[i] == max1){
            max1_count++;
        }
    }
    
    if(max1_count > 1){
        max1_count--;
        max2 = max1;
    }
    else{
        for(int i = 0; i < A.size(); i++){
            if(A[i] > max2 && max1 > A[i]){
                max2 = A[i];
                max2_count = 1;
            }
            else if(A[i] == max2 && max1 > A[i]){
                max2_count++;
            }
        }
    }
    
    if(max1_count > 1){
        max3 = max1;
    }
    else if(max2_count > 1){
        max3 = max2;
    }
    else{
        for(int i = 0; i < A.size(); i++){
            if(A[i] > max3 && max2 > A[i] && max1 > A[i]){
                max3 = A[i];
            }
        }
    }
    
    if(neg1 == INT_MIN || neg2 == INT_MIN){
        return (int)max1*max2*max3;
    }
    
    return (int)max(max1*max2*max3, max1*neg1*neg2);
}

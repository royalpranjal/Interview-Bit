// https://www.interviewbit.com/problems/painters-partition-problem/

bool isPossible(long long int mid, vector<int> C, int paint){
    int maxi = 0;
    for(int i = 0; i < C.size(); i++){
        if(C[i] > maxi){
            maxi = C[i];
        }
    }
    
    if(maxi > mid){
        return false;
    }
    
    long long int sum = 0;
    int count = 1;
    
    for(int i = 0; i < C.size();){
        if((sum + (long long int)C[i]) > mid){
            count++;
            sum = 0;
        }
        else{
            sum = sum + (long long int)C[i];
            i++;
        }
    }
    
    if(count <= paint){
        return true;
    }
    
    return false;
}

int Solution::paint(int A, int B, vector<int> &C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    long long int start = 0, end = 0;
    
    for(int i = 0; i < C.size(); i++){
        end = end + C[i];
    }
    
    long long int sol = INT_MAX;
    
    while(start <= end){
        long long int mid = start + (end - start)/2;
        if(isPossible(mid, C, A)){
            sol = min(sol, mid);
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    
    return (int)((sol * (long long) B) % 10000003);
}

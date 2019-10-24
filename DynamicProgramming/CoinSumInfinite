// https://www.interviewbit.com/problems/coin-sum-infinite/

int Solution::coinchange2(vector<int> &A, int B) {

    int ways[B+1];
    memset(ways, 0, sizeof(ways));
    
    ways[0] = 1;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = A[i]; j <= B; j++){
            ways[j] = ways[j] + ways[j-A[i]];
            ways[j] = ways[j]%1000007;
        }
    }
    
    return ways[B];
}

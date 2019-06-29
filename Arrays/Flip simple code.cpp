/*
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
For example,
S = 010
Output = [1 1]
*/

vector<int> Solution::flip(string A) {
    int n = A.length();
    int ones = 0;
    int zeros = 0;
    int L = INT_MAX, R = 0;
    int ansL = 0, ansR = 0;
    int prev = 0;
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        ones += A[i] == '1';
        zeros += A[i] == '0';
        if (zeros) found = true;
        
        if (ones > zeros) {
            ones = 0;
            zeros = 0;
            L = INT_MAX;
            R = 0;
        } else if (A[i] == '0') {
            L = min(L, i);
            R = i;
            
            if (zeros - ones > prev) {
                ansR = R;
                ansL = L;
                prev = zeros - ones;
            }
        }
    }
    
    vector < int > ans;
    if (found) {
        ans.push_back(ansL + 1);
        ans.push_back(ansR + 1);
    }
    return ans;
}

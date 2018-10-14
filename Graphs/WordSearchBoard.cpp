vector<int> x({0, 1, -1, 0});
vector<int> y({1, 0, 0, -1});
 
// Check if the coordinates are safe to visit
bool isSafe(int a, int b, int c, int d){
    if(a >= 0 && a < c && b >= 0 && b < d)return true;
    return false;
}


void explore(bool& pivot, int val, int a, int b, vector<string>& A, string B){
    // If reached on the last index of the string,
    // it means we have found the reqd. string and 
    // so we return
    if(val == B.size()-1){
        pivot = true;
        return;
    }

    for(int i = 0; i < x.size(); i++){
        int first = a + x[i];
        int second = b + y[i];
        
        // Explore the adjacent node only if its value is the next index in the
        // given string
        if(isSafe(first, second, A.size(), A[0].size()) && A[first][second] == B[val+1]){
            explore(pivot, val+1, first, second, A, B);
            // To reduce time limit.
            if(pivot == true)return;
        }
    }

}

int Solution::exist(vector<string> &A, string B) {
    int l = A.size(), m = A[0].size();
    if(l == 0)return 0;

    bool pivot = false;
    for(int i = 0; i < l; i++){
        for(int k = 0; k < m; k++){
            if(A[i][k] == B[0]){
                explore(pivot, 0, i, k, A, B);
            }
            if(pivot)return pivot;
        }
    }
    return pivot;
}

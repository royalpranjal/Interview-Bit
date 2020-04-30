int all(bool digits[], int B, int total) {
    bool isZero = digits[0] ? 1 : 0;
    long long int count = 1;
    if (B == 1) {
        return total;
    }
    count *= isZero ? total - 1 : total;
    count *= pow(total, B - 1);
    return count;
}
int compare(bool digits[], int B, int C, int total) {
    string c = to_string(C);
    vector<int> count(10);
    for (int i = 1; i < 10; i ++) {
        count[i] = digits[i - 1] + count[i - 1];
    }
    int dp[B + 1];
    dp[0] = 0;
    bool flag = 1;
    for (int i = 1; i <= B; i ++) {
        dp[i] = dp[i - 1] * total;
        if (flag || i == 1) {
            int smallCount = count[c[i - 1] - '0'];
            if (B != 1 && i == 1 && digits[0]) {
                smallCount --;
            }
            dp[i] += smallCount;
            if (!digits[c[i - 1] - '0']) {
                flag = false;
            }
        }
    }
    return dp[B];
}
int Solution::solve(vector<int> &A, int B, int C) {
    int length = log10(C) + 1;
    bool digits[10] = {0};
    int total = 0;
    for (int i = 0; i < A.size(); i ++) {
        digits[A[i]] = 1;
        total ++;
    }
    if (B > length || B == 0) {
        return 0;
    } else if (B < length) {
        return all(digits, B, total);
    } else {
        return compare(digits, B, C, total);    
    }
}

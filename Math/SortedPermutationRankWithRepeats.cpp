#define MOD 1000003
long long int fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return (fact(n - 1) * n) % MOD;
}
 long long int inverseNumber(int num) {
    long long int ans = 1, base = (long long) num;
    int power = MOD - 2;
    while (power > 0) {
        if (power == 1) {
            return (ans * base) % MOD;
        }
        if (power % 2 == 0) {
            base = (base * base) % MOD;
            power /= 2;
        } else {
            ans = (ans * base) % MOD;
            power--;
        }
    }
    return ans;
}
int Solution::findRank(string A) {
    if (A.size() <= 0) {
        return 0;
    }
    int alpha[52] = {0};
    for (int i = 0; i < A.size(); i ++) {
        if (islower(A[i])) {
            alpha[A[i] - 'a' + 26] ++;
        } else {
            alpha[A[i] - 'A'] ++;
        }
    }
    long long int total = 0;
    for (int i = 0; i < A.size(); i ++) {
        long long localCount = 0;
        int size = islower(A[i]) ? A[i] - 'a' + 26 : A[i] - 'A';
        long long int count = (fact(A.size() - i - 1));
        for (int j = 0; j < size; j ++) {
            if (alpha[j]) {
                alpha[j] --;
                localCount = count;
                for (int k = 0; k < 52; k ++) {
                    if (alpha[k]) {
                        localCount = (localCount * inverseNumber(fact(alpha[k]))) % MOD;
                    }
                }
                alpha[j] ++;
                total = (total + localCount) % MOD;
            }
        }
        if (islower(A[i])) {
            alpha[A[i] - 'a' + 26] --;
        } else {
            alpha[A[i] - 'A'] --;
        }
    }
    return (total + 1) % MOD;
}

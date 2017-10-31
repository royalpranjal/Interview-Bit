// https://www.interviewbit.com/problems/grid-unique-paths/

class Solution {
    public:
        int uniquePaths(int m, int n) {
            // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
            long long ans = 1;
            for (int i = n; i < (m + n - 1); i++) {
                ans *= i;
                ans /= (i - n + 1);
            }
            return (int)ans;
        }
};

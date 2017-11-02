// https://www.interviewbit.com/problems/grid-unique-paths/

// long long int permute(int x, int y){
//     long long int sol = 1;
//     for(int i = 1; i <= y; i++){
//         sol = sol*(x-i+1);
//     }
//     return sol;
// }

// long long int fact(int x){
//     if(x == 1){
//         return 1;
//     }
//     else{
//         return x*fact(x-1);
//     }
// }

int Solution::uniquePaths(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // Solution 1 (concise solution)
    // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
    long long ans = 1;
    for (int i = B; i < (A + B - 1); i++) {
        ans *= i;
        ans /= (i - B + 1);
    }
    return (int)ans;
    
    // Solution 2 
    // int x = A-1;
    // int y = B-1;
    
    // if(x == 0 || y == 0){
    //     return 1;
    // }
    
    // int small = x;
    // if(y < x){
    //     small = y;
    // }
    // int ans = int (permute(x+y, small)/fact(small));
    
    // return ans;
}

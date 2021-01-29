/*https://www.interviewbit.com/problems/find-nth-fibonacci/

Find Nth Fibonacci
Asked in:
Facebook

*/




    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // St
vector<vector<long long>> multiply(vector<vector<long long>>a,vector<vector<long long>>b){
    vector<vector<long long>>m(2, vector<long long>(2));

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            m[i][j]=0;
            for(int k=0;k<2;k++){
                m[i][j]+=((a[i][k]%1000000007)*(b[k][j]%1000000007))%1000000007;
            }
        }
    }
return m;
}
int Solution::solve(int n) {
   vector<vector<long long>>PS= {{1, 1},{1, 0}};
   vector<vector<long long>>P= {{1, 0},{0, 1}};
   while(n>0){
       if ((n%2)==1) P=multiply(P, PS);
            n=n/2; PS =multiply(PS, PS);
   }

return P[0][1]%1000000007;
}

// This Approch is based on Simple technique but may or may not pass the all testcases but an correct approch for leetcode and other platform

//And This 3rd approch will give a O(1) time complexity 100 % faster on leet code but may not pass some cases on interview bit

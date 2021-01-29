
//Counting Subarrays! 2 Times Asked in Uber


//Question:  https://www.interviewbit.com/problems/counting-subarrays/
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


int Solution::solve(vector<int> &A, int B) {
     int n=A.size();

      int cont=0,window=0;
       int sum=0;
       int i=0;
       while(i<n && window<n ){
           if(sum+A[i]<B){
               sum+=A[i];
               cont+=i-window+1;
               i++;
           }
           else {
               sum-=A[window];
               window++;
           }

       }
       return cont;
    }

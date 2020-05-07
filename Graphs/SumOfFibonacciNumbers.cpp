// https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

int Solution::fibsum(int n) {
    vector <int> fib;
 		fib.push_back(1);fib.push_back(1);      // now u have 1 and 1 at v[0] and v[1]
 		for(int i=2;fib[i-1]<n;i++){
 			int val=fib[i-1]+fib[i-2];
 			fib.push_back(val);
		 }
		 int ans=0;
		 int size=fib.size();
		 size--;
		 while(n>0){
		 	while(fib[size]>n){        // find the largest fibonaci number < n
		 		size--;
			 }                         // now decraese the largest fibonaci number from n
			 n=n-fib[size];
			 ans++;
		 }
		 return ans;
}



// int Solution::fibsum(int A) {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
//     vector<int> vec;
    
//     vec.push_back(1);
//     vec.push_back(1);
    
//     int fib, i = 2;
    
//     while(fib <= A){
//         fib = vec[i-2] + vec[i-1];
//         vec.push_back(fib);
//         i++;
//     }
    
//     int j = vec.size()-1;
//     int sol = 0;
    
//     LOOP:while(A && j >= 0){
//         if(vec[j] == A){
//             sol++;
//             return sol;
//         }
//         else if(vec[j] < A){
//             sol++;
//             A = A - vec[j];
//             goto LOOP;
//         }
//         j--;
//     }
    
//     return 0;
// }

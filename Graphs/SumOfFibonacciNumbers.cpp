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

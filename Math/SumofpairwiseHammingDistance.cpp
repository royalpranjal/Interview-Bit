//https://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/
int Solution::hammingDistance(const vector<int> &A) {

    long long int ans =0;
    
    for(int i=0;i<32;i++)
    {
        long long int count =0;
        for(int j=0;j<A.size();j++)
        {
            if(A[j] & (1<<i))
            count++;
        }
        
        ans = (ans + count * (A.size()-count) * 2)%1000000007;
    }
    
    return ans;
}

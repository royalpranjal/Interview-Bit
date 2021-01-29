
//Counting Subarrays!   Many Time Asked in these
 /*Facebook
Paypal
Yahoo
Microsoft
LinkedIn
Amazon
Goldman Sachs*/


//Question:  https://www.interviewbit.com/problems/counting-subarrays/
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

int Solution::maxSubArray(const vector<int> &A) {
    int max=INT_MIN;
    int sum=0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(sum<0)
            sum=0;
        else if(sum>max)
            max=sum;

    }
    return max;
}

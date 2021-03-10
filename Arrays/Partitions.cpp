/*
Link: https://www.interviewbit.com/problems/partitions/
Problem Description

You are given a 1D integer array B containing A integers.

Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.

Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])



Problem Constraints
1 <= A <= 105

-109 <= B[i] <= 109



Input Format
First argument is an integer A.

Second argument is an 1D integer array B of size A.



Output Format
Return a single integer denoting the number of ways to split the array B into three parts with the same sum.



Example Input
Input 1:

 A = 5
 B = [1, 2, 3, 0, 3]
Input 2:

 A = 4
 B = [0, 1, -1, 0]


Example Output
Output 1:

 2
Output 2:

 1


*/
#include <numeric>
int Solution::solve(int A, vector<int> &B) {
    int count = 0;
int sum = std::accumulate(B.begin(), B.end(), 0);

if(sum%3 == 0) {
    vector<int> prefix(A);
    vector<int> suffix(A);
    int runningSum = 0;
    for(int i = 0; i < A; i++) {
        suffix[i] = sum - runningSum;
        runningSum += B[i];
        prefix[i] = runningSum;
    }

    const int val = sum/3;
    for(int i = 0; i < A; i++) {
        if( prefix[i] == val) {
            for(int j = i+2; j < A; j++) {
                if( suffix[j] == val) {
                    count++;
                }
            }
        }
    }

}
return count;
}

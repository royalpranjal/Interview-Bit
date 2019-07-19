/*
Solution by : Bhavik Dhandhalya
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes
Length of given string s will always equal to n - 1
Your solution should run in linear time and space.

Input 1:

n = 3
s = ID
Return: [1, 3, 2]

Solution Complexity : O(N) time and O(1) space
Refer this URL for lexicographically smaller permutation solution:
https://leetcode.com/articles/find-permutation/
*/

vector<int> Solution::findPerm(const string A, int B) {
    vector < int > ans;
    int n = A.length();
    int maxi = n + 1, mini = 1;
    for (int i = 0; i < n; i++) {
        if (A[i] == 'I') ans.push_back(mini++);
        if (A[i] == 'D') ans.push_back(maxi--);
    }
    ans.push_back(maxi);
    return ans;
}

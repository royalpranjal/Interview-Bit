// O(n) Solution without sorting using frequency table

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> freq(n, 0);
    int small = 0; // stores how many elements are smaller than the current element

    for(int i=0; i<n; i++){
        if(A[i]<0)
            small++; // intially counts all negative numbers
        if(A[i]<0 || A[i]>=n)
            continue; // Only numbers between 0 to n-1 can be a solution
        freq[A[i]]++; // Count frequency of all elements in 0 to n-1
    }

    for(int i=0; i<n; i++){
        if(freq[i]==0) // Element doesnt exist - skip
            continue;
        small+=freq[i];
        if(n-small == i) // n-small elements are greater than i
            return 1;
    }

    return -1;
}

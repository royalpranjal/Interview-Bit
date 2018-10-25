// https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A) {
    // Base case     
    if(A.size() <= 1)return 0;
    
    // Make two arrays such that one of them holds the minimum from the left
    // and the other holds maximum from the right
    vector<int> v1 (A.size(), 0), v2(A.size(), 0);
    
    // Fill the first array with minimum from the left
    v1[0] = A[0];
    for(int i = 1 ; i < A.size(); i++)v1[i] = min(v1[i-1], A[i]);
    
    // Fill the second array with maximum from the right
    v2[A.size()-1] = A[A.size()-1];
    for(int i = A.size()-2 ; i >= 0 ; i--)v2[i] = max(v2[i+1], A[i]);
    
    
    int i = 0, j = 0;
    int ans = -1;
    // While we don't traverse the complete array, check if the minimum element is indeed
    // less than the maximum element in the other array, if yes, update the answer.
    // Move the pointer as required. If the element in second array is greater than
    // that in first array, keep moving the second pointer and update the answer
    // else move the first pointer.
    while(j < A.size() && i < A.size()){
        if(v2[j] >= v1[i]){
            if(j-i > ans){
                ans = j-i;
            }
            j = j + 1;
        }else i = i + 1;
    }
    return ans;
}




// Here we are making an array to check whether all the elements on the left of an index are smaller than it or not
// If true then we are checking for greater j such that A[j] is greater than A[i]. If so then that j is greater than all i on the left
// also. On finding such a j or a false in the check array, we decrement i.

// int Solution::maximumGap(const vector<int> &A) {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
//     vector<bool> tempArr(A.size());
//     int min = A[0];
//     int max_distance = 0;
//     int i = A.size()-1;
//     int j = A.size()-1;
    
//     for(int i = 0; i < A.size(); i++){
//         if(A[i] > min){
//             tempArr[i] = false;
//         }
//         else{
//             min = A[i];
//             tempArr[i] = true;
//         }
//     }

//     LOOP:while(i >= 0){
//         if(tempArr[i] == false){
//             i--;
//             goto LOOP;
//         }
//         while((A[i] > A[j]) && (j > i)){
//             j--;
//         }
//         if((j-i) > max_distance){
//             max_distance = j-i;
//         }
//         i--;
//     }
//     return max_distance;
// }

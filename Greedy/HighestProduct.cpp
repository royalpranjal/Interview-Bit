int Solution::maxp3(vector<int> &A) {
     
    sort(A.begin(), A.end());   //sort all numbers
     
    int n = A.size(); 
    // Now as last three number are greater among all and if all the three last numbers are positive and negative then max pdt will all_pos.If only 2 elements in the array are positive
    // then the pdt of three number (i.e.maximum) is negative which means maximum comes in this case is also from all_pos
    int all_pos = A[n-3]*A[n-2]*A[n-1]; 
    // One case in which there is only one positive number in this case can take two negative numbers which on multipling becomes positive so for that we pick those number from A[0] & A[1]
    // becoz A[0] and A[1] are minimum and negative multipling gives biggest.
    int pos_neg = A[0]*A[1]*A[n-1];      
     
    return max(all_pos, pos_neg);  // maximum of all_pos & pos_neg
     
}

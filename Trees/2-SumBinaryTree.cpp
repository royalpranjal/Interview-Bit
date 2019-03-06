// https://www.interviewbit.com/problems/2-sum-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// A shorter and intuitive method. Check out the next two solutions as well.
int Solution::t2Sum(TreeNode* A, int B) {
    // Base Case
    if(!A)return 0;
    
    // Make two stacks for the two different traversals,
    // one from the right side, other from the left.
    stack<TreeNode*> s1, s2;
    TreeNode* temp1 = A, *temp2 = A;
    
    // Take temp1 to the extreme left
    while(temp1){
        s1.push(temp1);
        temp1 = temp1->left;
    }
    
    // and temp2 to extreme right
    while(temp2){
        s2.push(temp2);
        temp2 = temp2->right;
    }
    temp1 = s1.top();
    temp2 = s2.top();
    
    // While we do not traverse the complete tree
    while(temp1 and temp2 and temp1->val < temp2 -> val){
        if(temp1->val + temp2->val == B)return 1;

        if(temp1->val + temp2->val < B){
            // Move Ahead the temp1 pointer
            s1.pop();
            // Check out the preorder traversal using stacks 
            temp1 = temp1->right;
            while(temp1){
                s1.push(temp1);
                temp1 = temp1->left;
            }
            temp1 = s1.top();
        }else{
            // Move ahead the temp2 pointer
            s2.pop();
            // Inverse of preorder traversal using stacks 
            // (not to be confused with postorder traversal)
            temp2 = temp2->left;
            while(temp2){
                s2.push(temp2);
                temp2 = temp2->right;
            }
            temp2 = s2.top();
        }
    }
    return 0;
}


// int Solution::t2Sum(TreeNode* A, int B) {
    
//     stack<TreeNode*> st1;
//     stack<TreeNode*> st2;
    
//     int val1 = 0, val2 = 0;
//     int done1 = 0, done2 = 0;
    
//     TreeNode* curr1 = A;
//     TreeNode* curr2 = A;
    
    
//     while(1){
//         while(done1 == 0){
//             if(curr1 != NULL){
//                 st1.push(curr1);
//                 curr1 = curr1->left;
//             }
//             else{
//                 if(st1.empty()){
//                     done1 = 1;
//                 }
//                 else{
//                     curr1 = st1.top();
//                     val1 = curr1->val;
//                     st1.pop();
//                     curr1 = curr1->right;
//                     done1 = 1;    
//                 }
//             }
//         }
        
//         while(done2 == 0){
//             if(curr2 != NULL){
//                 st2.push(curr2);
//                 curr2 = curr2->right;
//             }
//             else{
//                 if(st2.empty()){
//                     done2 = 1;
//                 }
//                 else{
//                     curr2 = st2.top();
//                     st2.pop();
//                     val2 = curr2->val;
//                     curr2 = curr2->left;
//                     done2 = 1;
//                 }
//             }
//         }
        
//         if(((val1 + val2) == B) && (val1 != val2)){
//             return 1;
//         }
//         else if((val1 + val2) < B){
//             done1 = 0;
//         }
//         else if((val1 + val2) > B){
//             done2 = 0;
//         }
        
//         if(val1 >= val2){
//             return 0;
//         }
//     }
    
//     return 0;
// }

/*
Another method if you are unable to get above method, although both of them work the same.
*/


// bool isPairPresent(int K, TreeNode* A, TreeNode* B, stack<TreeNode*> s1, stack<TreeNode*> s2){
//     // Base Case
//     if(!A)return 0;

//     // Go to the extreme left
//     while(A){
//         s1.push(A);
//         A = A ->left;
//     }
//     // Go to the extreme right
//     while(B){
//         s2.push(B);
//         B = B->right;
//     }

//     Get the lowest and highest elements.
//     A = s1.top(); s1.pop();
//     B = s2.top(); s2.pop();
    
//     // Make the extremes as lowest and highest values (coz BST)
//     int low = A->val, high = B->val;
//     bool b1 = true;
//     bool b2 = true;
//     // While we don't cross the two pointers
//     while(low < high){
//         // Return if we have found the sum
//         if(low + high == K)return 1;
//         // If the sum is less, increase the lower pointer only.
//         if(low + high < K){
//             b2 = false;
//             b1 = true;
//         }
//         // Else decrement the higher pointer only.
//         else {
//             b2 = true;
//             b1 = false;
//         }
//         if(b1){
//             // If the pointer is not NULL, take it to the extreme left
//             // of its right child
//             if(A){
//                 A = A->right;
//                 while(A){
//                     s1.push(A);
//                     A = A->left;
//                 }
//             }
//             // Else just pop the top of the stack and make it as the lowest pointer.
//             else {
//                 A = s1.top();
//                 s1.pop();
//                 low = A->val;
//             }
//         }
//         // Same as above.
//         else if(b2){
            
//             if(B){
//                 B = B->left;
//                 while(B){
//                     s2.push(B);
//                     B = B->right;
//                 }
//             }else {
//                 B = s2.top();
//                 s2.pop();
//                 high = B->val;
//             }
//         }
//     }
//     return 0;
// }

// int Solution::t2Sum(TreeNode* A, int B) {
//     stack<TreeNode*> s1, s2;

//     TreeNode *head1 = A, *head2 = A;
    
//     return isPairPresent(B, head1, head2, s1, s2);
// }

// https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int sum(TreeNode* root, int val){
    if(root == NULL){
        return 0;
    }
    
    val = (((val)%1003*10)%1003 + (root->val)%1003)%1003;
    
    if(root->left == NULL && root->right == NULL){
        return val;
    }
    
    return (sum(root->left, val)%1003 + sum(root->right, val)%1003)%1003;
}

int Solution::sumNumbers(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return sum(A, 0);
}

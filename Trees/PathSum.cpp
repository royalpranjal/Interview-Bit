// https://www.interviewbit.com/problems/path-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int checkSum(TreeNode* root, int sum){
    if(root == NULL){
        return 0;
    }
    
    if(root->val == sum && root->left == NULL && root->right == NULL){
        return 1;
    }
    
    return max(checkSum(root->left, sum - root->val), checkSum(root->right, sum - root->val));
}

int Solution::hasPathSum(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return checkSum(A, B);
}

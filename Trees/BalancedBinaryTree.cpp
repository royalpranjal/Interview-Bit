// https://www.interviewbit.com/problems/balanced-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int checkBalanced(TreeNode* root){
    if(root == NULL){
        return 1;
    }
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else if(root->left != NULL && root->right != NULL){
        return min(checkBalanced(root->right), checkBalanced(root->left));
    }
    else if(root->left == NULL){
        if(root->right != NULL){
            TreeNode* temp = root->right;
            if(temp->right != NULL || temp->left != NULL){
                return 0;
            }
        }
        return 1;
    }
    else if(root->right == NULL){
        if(root->left != NULL){
            TreeNode* temp = root->left;
            if(temp->right != NULL || temp->left != NULL){
                return 0;
            }
        }
        return 1;
    }
    return 1;
}
 
int Solution::isBalanced(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return checkBalanced(A);
    
}

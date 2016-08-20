// https://www.interviewbit.com/problems/min-depth-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int depth(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else if(root->left == NULL && root->right != NULL){
        return 1 + depth(root->right);
    }
    else if(root->left != NULL && root->right == NULL){
        return 1 + depth(root->left);
    }
    return min(1 + depth(root->right), 1 + depth(root->left));
}

int Solution::minDepth(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return depth(A);
    
}

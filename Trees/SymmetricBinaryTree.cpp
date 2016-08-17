// https://www.interviewbit.com/problems/symmetric-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int chSy(TreeNode* lft, TreeNode* ryt){
    if(lft == NULL && ryt == NULL){
        return 1;
    }
    else if((lft == NULL && ryt != NULL) || (lft != NULL && ryt == NULL)){
        return 0;
    }
    else if(lft->val == ryt->val){
        return min(chSy(lft->left, ryt->right), chSy(lft->right, ryt->left));
    }
    return 0;
} 

int checkSym(TreeNode* root){
    if(root == NULL){
        return 1;
    }
    return chSy(root->left, root->right);
} 

int Solution::isSymmetric(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return checkSym(A);
}

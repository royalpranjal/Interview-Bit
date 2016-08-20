// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void putSum(TreeNode* root, vector<vector<int> >& sol, int sum, vector<int>& v){
    if(sum == 0 && root->left == NULL && root->right == NULL){
        sol.push_back(v);
    }
    
    if(root->left != NULL){
        v.push_back((root->left)->val);
        putSum(root->left, sol, sum - (root->left)->val, v);
        v.pop_back();
    }
    
    if(root->right != NULL){
        v.push_back((root->right)->val);
        putSum(root->right, sol, sum - (root->right)->val, v);
        v.pop_back();
    }
    
}

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > sol;
    vector<int> v;
    
    if(root == NULL){
        return sol;
    }
    
    v.push_back(root->val);
    
    putSum(root, sol, sum - root->val, v);
    
    return sol;
}

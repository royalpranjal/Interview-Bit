// https://www.interviewbit.com/problems/level-order/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    vector<int> ans;
    vector<vector<int> > sol;
    queue<TreeNode* > q;
    q.push(A);
    
    while(!q.empty())
    {
        int n = q.size();
        //for all nodes at current level
        while(n > 0)
        {
            TreeNode* node = q.front();
            ans.push_back(node->val);
            q.pop();
            if (node->left != NULL)  
                q.push(node->left);  
            if (node->right != NULL)  
                q.push(node->right);  
            n--;
        }   
        sol.push_back(ans);
        ans.clear();
    }    
    return sol;
}

/*
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > sol;
    vector<int> temp;
    queue<TreeNode*> q;
    queue<int> level;
    
    if(A == NULL){
        return sol;
    }
    
    q.push(A);
    level.push(0);
    
    while(!q.empty()){
        TreeNode* curr = q.front();
        int lev = level.front();
        if(sol.size() != level.front()+1){
            sol.push_back(temp);
        }
        sol[lev].push_back(curr->val);
        if(curr->left != NULL){
            q.push(curr->left);
            level.push(lev+1);
        }
        if(curr->right != NULL){
            q.push(curr->right);
            level.push(lev+1);
        }
        q.pop();
        level.pop();
    }
    
    return sol;
}
*/

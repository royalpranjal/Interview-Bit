/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > v;
    if(A == NULL)return v;
    
    queue<pair <TreeNode*, int> > q;
    q.push({A, 0});
    
    map<int, vector<int> > mp;
    while(!q.empty()){
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        
        if(temp.first->left){
            q.push({temp.first->left, temp.second-1});
        }
        if(temp.first->right){
            q.push({temp.first->right, temp.second+1});
        }
        
        mp[temp.second].push_back(temp.first->val);
    }

    for(map<int, vector<int> >::iterator it = mp.begin(); it != mp.end(); it++){
        v.push_back(it->second);
    }
    return v;
}

// struct node{
//     TreeNode* root;
//     int dis;
// };

// void make(map<int, vector<int> >& m, queue<node>& q){
//     if(q.size() == 0){
//         return;
//     }
    
//     TreeNode* root = (q.front()).root;
//     int dis = (q.front()).dis;
    
//     if(!root){
//         return;
//     }
    
//     m[dis].push_back(root->val);
    
//     q.pop();
    
//     if(root->left){
//         node l1;
//         l1.root =  root->left;
//         l1.dis = dis-1;
//         q.push(l1);
//     }
    
//     if(root->right){
//         node l1;
//         l1.root =  root->right;
//         l1.dis = dis+1;
//         q.push(l1);
//     }
    
//     make(m, q);
// }

// vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
//     map<int, vector<int> > m;
//     vector<vector<int> > sol;
//     queue<node> q;
    
//     node n;
//     n.root = A;
//     n.dis = 0;
    
//     q.push(n);
    
//     make(m, q);
    
//     map<int, vector<int> > :: iterator it = m.begin();
    
//     int curr = 0;
    
//     while(it != m.end()){
//         vector<int> temp;
//         sol.push_back(temp);
        
//         temp = it->second;
        
//         for(int i = 0; i < temp.size(); i++){
//             sol[curr].push_back(temp[i]);
//         }
        
//         curr++;
//         it++;
//     }
    
//     return sol;
// }

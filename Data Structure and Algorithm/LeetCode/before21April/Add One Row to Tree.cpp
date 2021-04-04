/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        
        vector<TreeNode*> que;
        
        que.push_back(root);
        int level = 0;
        
        while(!que.empty()){
            ++level;
            int N = que.size();
            for(int i = 0; i < N; i++){
                TreeNode* n = *que.begin();
                que.erase(que.begin());
                
                if(level == d-1 and n != nullptr){
                    TreeNode* tleft = n->left;
                    TreeNode* tright = n->right;
                    
                    TreeNode* newLeft = new TreeNode(v);
                    TreeNode* newRight = new TreeNode(v);
                    
                    newLeft->left = tleft;
                    newRight->right = tright;
                    
                    n->left = newLeft;
                    n->right = newRight;       
                }
                if(n->left != nullptr) que.push_back(n->left);
                if(n->right != nullptr) que.push_back(n->right);
            }
        }
        
        return root;
    }
};

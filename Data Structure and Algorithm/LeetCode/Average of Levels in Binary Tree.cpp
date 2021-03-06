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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*> queue;
        vector<double> result;
        
        queue.push_back(root);
        int level = 0;
        while(!queue.empty()){
            cout << level << "\n";
            ++level;
            
            double sum = 0;
            int count = 0;
            int size = queue.size();
            for(int i = 0; i < size; ++i){  
                TreeNode* node = *queue.begin();
                queue.erase(queue.begin());
                sum += node->val;
                ++count;
                
                if(node->left) queue.push_back(node->left);
                if(node->right) queue.push_back(node->right);
            }
            result.push_back((double)sum/count);      
        }
        
        return result;
    }
};

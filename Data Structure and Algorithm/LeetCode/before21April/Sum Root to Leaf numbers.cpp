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
    int total = 0;
    int sumNumbers(TreeNode* root) {
        int sum=0;
        solve(root, sum);
        
        return total;
    }
    
    void solve(TreeNode* r, int sum)
    {
        if(r == nullptr) return;
        
        sum *= 10;
        sum += r->val;
        
        if(r->left == nullptr and r->right == nullptr){
            total += sum;
            cout << "sum " << sum << " total " << total << "\n";
        }

        
        solve(r->left, sum);
        solve(r->right, sum);
        
    }
};

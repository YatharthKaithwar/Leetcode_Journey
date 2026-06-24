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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        
        // Handle empty tree case
        if (!root) return ans;
        
        // Queue for BFS, initialized with root
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> Level;
            int size = q.size(); // Number of nodes at current level
            
            // Process all nodes at current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Add node value to current level
                Level.push_back(node->val);
                
                // Add children to queue for next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Add current level to result
            ans.push_back(Level);
        }
        
        return ans;
    }
};
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
    void solve(TreeNode* root, int &sum){
        if(!root){
            return;
        }

        solve(root->right,sum);// going right of root to find all greater values
        sum += root->val;// adding the root's value to sum
        root->val = sum;// updating roots value to sum value
        solve(root->left, sum);// going left
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        return root;
    }
};
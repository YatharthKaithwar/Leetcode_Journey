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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)return 0;

        if(root->val < low){// then will not go to the left of node
            return rangeSumBST(root->right,low,high);
        }
        if(root->val>high){/// then will not go to the right of the node
            return rangeSumBST(root->left,low,high);
        }
        // adding-up node value and left right ranged values
        return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
};
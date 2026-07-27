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
    int minDiff = INT_MAX;
    void inOrder(TreeNode* root, TreeNode* &prev){// intution of inorder for valid sequence in acsending order BST
        if(!root)return;

        inOrder(root->left,prev);// going left node
        if(prev!=NULL){
            minDiff = min(minDiff,root->val - prev->val);// absolute difference of previous and node value
        }
        prev = root;// updating previous
        inOrder(root->right,prev);// going right
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        inOrder(root,prev);
        return minDiff;
    }
};
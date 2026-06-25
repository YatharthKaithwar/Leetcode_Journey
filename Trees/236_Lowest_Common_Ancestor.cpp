/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* Left = lowestCommonAncestor(root->left, p, q); // Recursively traversing left  node first
        TreeNode* Right = lowestCommonAncestor(root->right, p, q);// Traversing Right if left is NULL

        if(Left==NULL){      // If Left is NULL then returning right node
            return Right;
        }
        else if(Right==NULL){// if right is NULL then Return left
            return Left;
        }
        else{
            return root; //  If both is NULL then it is root node 
        }
    }
};
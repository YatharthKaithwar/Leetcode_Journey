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
private:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root){
        if(root==NULL)return;
      inorder(root->left);

      if(prev!=NULL && prev->val > root->val){ // if previous value is greater than the root value
        if(first == NULL){
            first = prev; // first violation
        }
        
            second = root; //update second
        
      }
      prev = root;

      inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
         if (first && second) {
            swap(first->val, second->val);
        }
    }
};
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
class Solution {                                            //                (ROOT)
public:                                                     //          (LEFT)      (RIGHT) 
    vector<int> rightSideView(TreeNode* root) {                
        vector <int> res;
        recursion (root,0,res);
        return res;
    }
public:
void recursion(TreeNode* root, int level, vector <int> &res){
    if(root==NULL)return;
    if(res.size()==level)res.push_back(root->val); // for first time entering the element in vector list //
    recursion(root->right, level+1, res);          // right side view and +1 to level //
    recursion(root->left, level+1, res);           // traverse left of root for right side view and +1 to level //
}
};
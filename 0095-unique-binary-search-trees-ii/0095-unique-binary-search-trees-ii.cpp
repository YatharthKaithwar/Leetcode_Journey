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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)return {};
        return buildTree(1,n);
    }
private: 
    vector<TreeNode*> buildTree(int start, int end){
        vector<TreeNode*> result;

        if(start>end){
            result.push_back(NULL);
            return result;
        }
        if(start == end){
            TreeNode* root = new TreeNode(start);
            return  {root};
        }
        for(int i=start; i<=end;i++){
            vector<TreeNode*> leftSubTree = buildTree(start,i-1);
            vector<TreeNode*> rightSubTree = buildTree(i+1,end);

            for(TreeNode* left: leftSubTree){
                for(TreeNode* right : rightSubTree){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
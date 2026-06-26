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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inorderMap; // For storing inorder values to further find root in it //
        for(int i=0; i<inorder.size();i++){    // adding values in map //
            inorderMap[inorder[i]]=i;
        }
        TreeNode* root =  buildTree(preorder,0,preorder.size()-1, 
                                    inorder, 0,inorder.size()-1, inorderMap);
                                    return root;
    }
        TreeNode* buildTree(vector<int>& preorder,int preorderStart,int preorderEnd, 
                            vector<int>& inorder, int inorderStart, int inorderEnd, map<int, int>& inorderMap){
        
        if (preorderStart > preorderEnd || inorderStart > inorderEnd) return NULL; // for NULL //

        TreeNode* root = new TreeNode(preorder[preorderStart]); // Root is the first element from preorder list //

        int inorderRoot=inorderMap[root->val];     // finding root in inorder list from preorder list //
        int numsLeft = inorderRoot - inorderStart; // Left out numbers in inorder list in left side of root element //

        root->left = buildTree(preorder,preorderStart+1, preorderStart + numsLeft, // left of root using preorder and inorder recursion
                              inorder, inorderStart, inorderRoot-1, inorderMap);
        root->right = buildTree(preorder,preorderStart+numsLeft+1, preorderEnd, // right  of root using preorder and inorder recursion
                              inorder, inorderRoot+1, inorderEnd, inorderMap);                      
        return root;
    }
    
};
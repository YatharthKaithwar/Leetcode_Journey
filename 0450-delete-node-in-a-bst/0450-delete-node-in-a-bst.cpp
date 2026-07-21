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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            return connection(root); // connecting node if root is equal to the key
        }
        TreeNode* dummy = root;// saving root node as dummy node
        while(root!=NULL){
            if(root->val > key){// if key value is in left of root
                if(root->left != NULL && root->left->val == key){
                    root->left = connection(root->left);// root left connection
                    break;
                }
                else{// going left of root
                    root = root->left;
                }
            }
            else{// else key value is on right of root
                if(root->right != NULL && root->right->val == key){
                    root->right = connection(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return dummy;//  returning the dummy node
    }
    TreeNode* connection(TreeNode* root){// connection function
        if(root->left == NULL){// if root left is null
            return root->right;// return the right node
        }
        else if(root->right == NULL){// if right is NULL
            return root->left;// return left node
        }
        TreeNode* rightChild = root->right;// right child connection
        TreeNode* lastRight = findLastRight(root->left);// for  finding rightmost node of the leftout root
        lastRight->right = rightChild;
        return root->left;
    }
    TreeNode* findLastRight(TreeNode* root){// for finding the right most root of the tree
        if(root->right == NULL){
            return root;
        }
        return findLastRight(root->right);
    }
};
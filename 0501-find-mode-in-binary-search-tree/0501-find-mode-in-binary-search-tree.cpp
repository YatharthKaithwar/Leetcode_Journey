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
    unordered_map <int,int> mp;// map holds {value,frequency}

    void inorder(TreeNode* root){
        if(!root)return;

        inorder(root->left);
        mp[root->val]++;
        inorder(root->right);// add all values in map
      
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);

        vector<int> result;
        int maxFreq = 0;
        for(auto &it : mp){//iteration
            if(it.second > maxFreq){// frequency is greater than the maxFrequency
                maxFreq = it.second;// save the frequency as max Frequency
                result = {};
                result.push_back(it.first);// pushing the value in the result
            }
            else if(it.second == maxFreq){
                result.push_back(it.first);
            }
        }return result;
    }
};
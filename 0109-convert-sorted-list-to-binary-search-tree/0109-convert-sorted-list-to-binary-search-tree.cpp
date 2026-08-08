/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next == NULL) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slowPrev = NULL;

        while(fast!=NULL && fast->next!=NULL){// finding middle node of the list
            slowPrev = slow;//saving slow's previous node to disconnect it's next node
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        slowPrev->next = NULL;//disconnecting the next node(mid node)
        root->left = sortedListToBST(head);// recursively make left sub tree
        root->right = sortedListToBST(slow->next);// recursively make right sub tree
        return root;
    }
};
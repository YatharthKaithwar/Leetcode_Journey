/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        while(node->next != NULL){// running till end
            node->val = node->next->val;// setting node value as its next node's value

            prev = node;// prev as node

            node = node->next;// node as its next node (moving forward)
        }
        prev->next = NULL;// 
        delete(node);// deleting the last node as it is null
    }
};
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if (!head || left == right) {
            return head;
        }

        // Dummy node simplifies handling when left == 1
        ListNode* dummy = new ListNode(0); // Dummy node simplifies handling when left == 1
        dummy->next = head;
        
        // Step 1: Move 'prev' to the node just before the reversal section
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // 'tail' is the first node of the sublist to be reversed.
        // After reversal, it will be the last node of the sublist.
        ListNode* tail = prev->next;

        // Step 2: Reverse the sublist [left, right]
        // We perform (right - left) swaps.
        // In each iteration, we move the node after 'tail' to become 'prev->next'.
        for (int i = 0; i < right - left; ++i) {
            ListNode* cache = tail->next;       // Node to be moved (current successor of tail)
            
            tail->next = cache->next; // Detach 'cache' from its current position
            
            cache->next = prev->next; // Insert 'cache' at the beginning of the reversed section (after 'prev')
            prev->next = cache;
        }

        ListNode* newHead = dummy->next;// Retrieve result and clean up dummy node
        delete dummy;
        return newHead;
    }
};
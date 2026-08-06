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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return NULL;
        }
        ListNode* prevSlow = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            prevSlow = slow;// assing slow to prevSlow
            slow = slow->next;// moving slow 1 step ahead
            fast = fast->next->next;// moving fast 2 steps ahead
        }
        prevSlow->next = slow->next;// connecting prevSlow to slow->next (removing slow(middle))
        delete(slow);
        return head;
    }
};
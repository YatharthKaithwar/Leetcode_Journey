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
    void reorderList(ListNode* head) {
        if(head==NULL && head->next==NULL)return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;    // Using Slow Fast to find middle  node //
            fast = fast->next->next;

        }

        ListNode* secondHalf = slow->next;  // Head of Second half //
        slow->next = NULL;                  // Splitting first half from second half by appointing slow->next as NULL//
        secondHalf =reverseList(secondHalf);// Reverse List //

        ListNode* firstHalf = head;
        while(secondHalf!=NULL){
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next= temp1;
            
            firstHalf = temp1;
            secondHalf = temp2;

        }
    }
private:
    ListNode*  reverseList(ListNode* head){ // Reverse function // 
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr!=NULL){
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};
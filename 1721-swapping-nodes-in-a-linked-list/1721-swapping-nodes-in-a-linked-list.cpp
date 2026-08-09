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
    int findLength(ListNode* head){
        int l = 0;
        while(head!=NULL){
            head=head->next;
            l++;
        }
        return l;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int length = findLength(head);
        int front = k;
        ListNode* K1 = head;
        while(front>1){//finding first node
            K1=K1->next;
            front--;
        }
        int back = length - k + 1;
        ListNode* K2 = head;
        while(back>1){// finding second node
            K2=K2->next;
            back--;
        }
        swap(K1->val,K2->val);// swapping both nodes
        return head;
    }
};
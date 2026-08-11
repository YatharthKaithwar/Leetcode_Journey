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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* left = NULL;
        ListNode* right = list1;

        for(int i = 0; i<=b; i++){
            if(i==a-1){
                left = right;// marking left just before a
            }
            right = right->next;// marking right node(b)

        }
        left->next = list2;// appointing left next as list 2 
        ListNode* temp = list2;
        while(temp->next!=NULL){
            temp=temp->next;// iterating list2 till end
        }
        temp->next = right;// making list 2 last element's next as right
        return list1;
    }
};
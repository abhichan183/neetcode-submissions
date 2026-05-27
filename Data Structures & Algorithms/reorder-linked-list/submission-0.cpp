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
        if(head==NULL||head->next== NULL) return;
        ListNode* tortoise=head;
        ListNode* hare=head->next;
        while(hare!=NULL && hare->next!=NULL){
            tortoise=tortoise->next;
            hare=hare->next->next;
        }
        ListNode* second=tortoise->next;
        tortoise->next=NULL;
        ListNode* prev=NULL;
        while(second!=NULL){
            ListNode* temp=second->next;
            second->next=prev;
            prev=second;
            second=temp;
        }
        ListNode* first=head;
        second=prev;
        while(second!=NULL){
            ListNode* l1=first->next;
            ListNode* l2=second->next;
            first->next=second;
            second->next=l1;
            first=l1;
            second=l2;
        }
    }
};

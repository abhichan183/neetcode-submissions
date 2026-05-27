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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* l=head;
        ListNode* r=head;
        if(head->next==NULL){
            return NULL;
        }
        int count=1;
        while(count!=n){
            r=r->next;
            count++;
        }
        if(r->next==NULL){
            return l->next;
        }
        ListNode* prev=head;
        l=l->next;
        r=r->next;
        while(r->next!=NULL){
            l=l->next;
            r=r->next;
            prev=prev->next;
        }
        prev->next=l->next;
        return head;
    }
};

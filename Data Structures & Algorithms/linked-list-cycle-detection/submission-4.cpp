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
    bool hasCycle(ListNode* head) {
        if(head==NULL) return false;
        if(head->next==NULL) return false;
        ListNode* tortoise=head;
        ListNode* hare=head->next->next;
        while(hare!=NULL && tortoise!=NULL){
                if(hare==tortoise) return true;
                hare=hare->next;
                if(hare==NULL) return false;
                else hare=hare->next;
                tortoise=tortoise->next;
        }
        return false;
    }
};

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
    int mi(ListNode* head){
        int x=0;
        while (head!=NULL){head=head->next;x++;}
        return x/2;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next==NULL){return NULL;}
        ListNode* ret=head;
        ListNode* pre=head;
        int k=mi(head);
        int b=k;
        while (b>1){pre=pre->next;b--;}
        pre->next=pre->next->next;
        return ret;
    }
};

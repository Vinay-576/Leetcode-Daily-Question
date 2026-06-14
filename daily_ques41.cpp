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
    int pairSum(ListNode* head) {
        ListNode *s = head, *f = head;
        int ans = 0;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode *prev = nullptr;
        while (s) {
            ListNode *nextNode = s->next;
            s->next = prev;
            prev = s;
            s = nextNode;
        }
        ListNode *fir = head;
        ListNode *sec = prev;
        while (sec) {
            ans = max(ans, fir->val + sec->val);
            fir = fir->next;
            sec = sec->next;
        }
        return ans;
    }
};

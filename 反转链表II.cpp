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
    ListNode *Reverse(ListNode *start, int left, int right){
        ListNode *pre = nullptr;
        ListNode *cur = start;
        ListNode *nxt = cur->next;
        int cnt = left;
        while(cnt < right) {
            pre = cur;
            cur = nxt;
            nxt = cur->next;
            cur->next = pre;
            cnt++;
        }
        // right的处理已经处理过了 只要处理start->next
        start->next = nxt;
        return cur;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;

        int cnt = 1;
        ListNode *start = head;
        ListNode *pre = nullptr;
        while(cnt < left){
            pre = start;
            start = start->next;
            cnt++;
        }

        ListNode *cur = Reverse(start, left, right);


        if(pre == nullptr)
            return cur;
        else {
            pre->next = cur;
            return head;
        }
    }
};
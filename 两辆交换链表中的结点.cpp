//递归

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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){ //空链表
            return head;
        }
        else{
            ListNode *tmp = head->next->next;
            head->next->next = head;
            head = head->next;
            head->next->next = swapPairs(tmp);
            return head;
        }
    }
};
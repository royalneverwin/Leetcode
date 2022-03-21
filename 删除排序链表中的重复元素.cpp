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
    ListNode* deleteDuplicates(ListNode* head) {
        int curVal;
        ListNode* curNode = head;
        ListNode* node;
        while(curNode != nullptr){
            node = curNode;
            curVal = curNode->val;
            while(node != nullptr && node->val == curVal){
                node = node->next;
            }
            curNode->next = node;
            curNode = node;
        }
        return head;
    }
};
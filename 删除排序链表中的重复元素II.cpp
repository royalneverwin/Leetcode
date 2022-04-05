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
        if(head == nullptr) // 特殊处理
            return head;
        ListNode *newHead = nullptr;
        ListNode *slow = nullptr;
        ListNode *fast = head;
        while(fast->next != nullptr){
            if(fast->val != fast->next->val){
                if(slow != nullptr) // slow != nullptr才连接
                    slow->next = fast;
                slow = fast;
                if(newHead == nullptr) // 初始化newHead
                    newHead = slow;
                fast = fast->next;
            }
            else{
                ListNode *tmp = fast->next;
                while(tmp != nullptr && tmp->val == fast->val)
                    tmp = tmp->next;
                if(tmp == nullptr){ // 遍历完了
                    if(slow != nullptr)
                        slow->next = nullptr;
                    return newHead;
                }
                fast = tmp;
            }
        }
        if(slow != nullptr)
            slow->next = fast;
        slow = fast;
        slow->next = nullptr;
        if(newHead == nullptr)
            newHead = slow;

        return newHead;
    }
};
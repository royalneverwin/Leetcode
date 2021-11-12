// 普通方法 遍历
// 优化代码：递归 p.s.递归确实是好东西啊！！

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr){
            return nullptr;
        }
        else if(l1 == nullptr){
            return l2;
        }
        else if(l2 == nullptr){
            return l1;
        }
        else{
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;
            if(l1->val < l2->val){
                l1->next = mergeTwoLists(next1, l2);
                return l1;
            }
            else{
                l2->next = mergeTwoLists(l1, next2);
                return l2;
            }
        }
    }
};
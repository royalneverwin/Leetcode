//最巧妙方法：递归，过于简单，这里就不实现了
//本方法：利用双指针找到倒数第n个结点，先让second走到第n个结点，再让first和second一起走，这样second走到头的时候first就是倒数第n个结点

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
        ListNode* record[3];
        int cnt = 1;
        ListNode *first = head;
        ListNode *prev = head;
        ListNode *second = head;
        while(cnt < n){ //将second定位到第n个结点
            second = second->next;
            cnt++;
        }
        if(second->next == nullptr){ //对删除第一个结点进行特殊处理
            return head->next;
        }
        while(second->next != nullptr){
            second = second->next;
            prev = first;
            first = first->next;
        }
        prev->next = first->next;
        return head;
    }
};
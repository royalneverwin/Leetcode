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
    ListNode* rotateRight(ListNode* head, int k) {
        // 计算节点总数
        int cnt = 0;
        ListNode* oldHead = head;

        while(head != nullptr){
            cnt++;
            head = head->next;
        }

        head = oldHead;


        // 如果0节点
        if(cnt == 0)
            return head;

        // 如果k == 0, 等于没旋转
        k = k % cnt;
        if(k == 0)
            return head;

        // 保存oldHead, 找到newHead, 将oldEnd连到oldHead, newHead前节点作为newOld
        ListNode* newHead, * newEnd, * oldEnd;
        int tmp = 1;
        while(tmp < cnt - k){
            head = head->next;
            tmp++;
        }
        newEnd = head;
        newHead = newEnd->next;
        newEnd->next = nullptr;
        head = newHead;
        while(head->next != nullptr)
            head = head->next;
        oldEnd = head;
        oldEnd->next = oldHead;

        return newHead;




    }
};
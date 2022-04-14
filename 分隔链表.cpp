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
    ListNode* partition(ListNode* head, int x) {


        ListNode *smallHead = nullptr, *bigHead = nullptr, *small, *big, *cur = head;
        while(cur != nullptr){
            if(cur->val < x){
                if(smallHead == nullptr){
                    smallHead = cur;
                    small = cur;
                    cur = cur->next;
                    small->next = nullptr;
                }
                else{
                    small->next = cur;
                    cur = cur->next;
                    small = small->next;
                    small->next = nullptr;
                }
            }
            else{
                if(bigHead == nullptr){
                    bigHead = cur;
                    big = cur;
                    cur = cur->next;
                    big->next = nullptr;
                }
                else{
                    big->next = cur;
                    cur = cur->next;
                    big = big->next;
                    big->next = nullptr;
                }
            }
        }

        if(smallHead != nullptr){
            head = smallHead;
            if(bigHead != nullptr)
                small->next = bigHead;
        }
        else
            head = bigHead;

        return head;
    }
};
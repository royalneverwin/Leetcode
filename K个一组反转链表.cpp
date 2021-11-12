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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode *tmp = head;
        while(tmp != nullptr){
            cnt++;
            if(cnt >= k){
                break;
            }
            tmp = tmp->next;
        }
        if(cnt < k){
            return head;
        }
        else{ //链表中有k个结点, 此时tmp指向第k个结点
            if(k == 1)
                return head;
            ListNode* ret = tmp;
            tmp = tmp->next;//tmp指向第k+1个指针
            ListNode* node1;//swap的第一个指针
            ListNode* node2;//swap的第二个指针
            ListNode* node1Prev;//node1的前一个指针
            ListNode* node1Next;//node1的下一个指针
            ListNode* node2Prev;//node2的前一个指针
            ListNode* node2Next;//node2的下一个指针
            //第一个指针和最后一个指针特殊处理
            node1 = node2 = head;
            node1Next = node1->next;
            for(int j = 0; j < k-1; j++){
                node2Prev = node2;
                node2 = node2->next;
            }
            node2Next = reverseKGroup(tmp, k);
            if(node2 == node1->next){
                node2->next = node1;
            }
            else{
                node2->next = node1Next;
                node2Prev->next = node1;
            }
            node1->next = node2Next;
            node1Prev = node2;
            for(int i = 1; i < k/2; i++){ //遍历
                node1 = node2->next;
                node2 = node2->next;
                node1Next = node1->next;
                for(int j = 0; j < k - 2*i - 1; j++){
                    node2Prev = node2;
                    node2 = node2->next;
                }
                node2Next = node2->next;
                node1Prev->next = node2;
                if(node2 == node1->next){
                    node2->next = node1;
                }
                else{
                    node2->next = node1Next;
                    node2Prev->next = node1;
                }
                node1->next = node2Next;
                node1Prev = node2;
            }
            return ret;
        }
    }
};
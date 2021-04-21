/*给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/add-two-numbers
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


/*
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *p1 = l1;
        struct ListNode *p2 = l2;
        struct ListNode *an = new struct ListNode();
        struct ListNode *p3 = an;
        int val1, val2;
        int addOne = 0;//判断是否要进位
        while(p1 != nullptr || p2 != nullptr){
            struct ListNode*tmp = new struct ListNode;
            if(p1 != nullptr){
                val1 = p1->val;
                p1 = p1->next;
            }
            else
                val1 = 0;
            if(p2 != nullptr){
                val2 = p2->val;
                p2 = p2->next;
            }
            else
                val2 = 0;
            tmp->val = (val1 + val2 + addOne)%10;
            addOne = (val1 + val2 + addOne)/10;
            p3->next = tmp;
            p3 = tmp;
        }
        if(addOne == 1){
            struct ListNode *tmp = new struct ListNode(1);
            p3->next = tmp;
        }
        return an->next;
    }
};
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
    ListNode *h;
public:
    // 链表非常大且长度未知, 该怎么处理？
    // 能否不使用额外空间？
    // 很明显, 如果用一个数组存放节点, 会非常方便, 但那样不符合规定
    // 合理解法：蓄水池算法/水塘抽样
    Solution(ListNode* head) {
        h = head;
    }

    int getRandom() {
        int index = 0, ans;
        ListNode *tmp = h;
        while(tmp != nullptr){
            index++;
            int i = random() % index;
            if(i == 0)
                ans = tmp->val;
            tmp = tmp->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
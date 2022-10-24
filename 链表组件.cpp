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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> us;
        for(auto i: nums) {
            us.insert(i);
        }
        int res = 0;
        int cur = 0;
        while(head != nullptr) {
            if(us.count(head->val)) {
                cur += 1;
            }
            else {
                if(cur > 0) {
                    res += 1;
                    cur = 0;
                }
            }
            head = head->next;
        }
        if(cur > 0) {
            res += 1;
            cur = 0;
        }
        return res;
    }
};
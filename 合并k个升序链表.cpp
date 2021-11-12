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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) //特殊处理，空vector
            return nullptr;
        ListNode *ret;
        int retVal = 100000;
        int index;
        bool flag = false; //判断是不是至少存在一个非空指针
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != nullptr){
                flag = true;
                break;
            }
        }
        if(!flag){
            return nullptr;
        }
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != nullptr){
                if(lists[i]->val < retVal){
                    ret = lists[i];
                    retVal = lists[i]->val;
                    index = i;
                    flag = true;
                }
            }
        }
        if(lists[index]->next == nullptr){
            lists.erase(lists.begin() + index);
        }
        else{
            lists[index] = lists[index]->next;
        }
        ret->next = mergeKLists(lists); //递归进行
        return ret;
    }
};
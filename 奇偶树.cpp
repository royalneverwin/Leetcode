/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 广搜
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> mq;
        mq.push(make_pair(root, 0));
        int value;
        int index = -1;
        while(!mq.empty()){
            pair<TreeNode*, int> tmp = mq.front();
            mq.pop();
            bool flag = false;
            if(tmp.second != index){
                index = tmp.second;
                flag = true;
            }
            if(index % 2 == 0){
                if(tmp.first->val % 2 == 0)
                    return false;
                if(!flag && tmp.first->val <= value)
                    return false;
            }
            else{
                if(tmp.first->val % 2 != 0)
                    return false;
                if(!flag && tmp.first->val >= value)
                    return false;
            }
            value = tmp.first->val;
            if(tmp.first->left != NULL)
                mq.push(make_pair(tmp.first->left, tmp.second + 1));
            if(tmp.first->right != NULL)
                mq.push(make_pair(tmp.first->right, tmp.second + 1));
        }
        return true;
    }
};
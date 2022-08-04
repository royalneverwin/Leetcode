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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode *, int>> qu;
        qu.push(make_pair(root, 1));
        while(true) {
            pair<TreeNode *, int> tmp = qu.front();
            qu.pop();
            if(tmp.first->left==nullptr && tmp.first->right==nullptr) {
                return tmp.second;
            }
            else {
                if(tmp.first->left) {
                    qu.push(make_pair(tmp.first->left, tmp.second+1));
                }
                if(tmp.first->right) {
                    qu.push(make_pair(tmp.first->right, tmp.second+1));
                }
            }
        }
    }
};
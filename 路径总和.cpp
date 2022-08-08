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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        queue<pair<TreeNode *, int>> qu;
        qu.push(make_pair(root, root->val));
        while(!qu.empty()) {
            pair<TreeNode *, int> tmp = qu.front();
            qu.pop();
            if(tmp.first->left==nullptr && tmp.first->right==nullptr) {
                if(tmp.second == targetSum)
                    return true;
            }
            else {
                if(tmp.first->left) {
                    qu.push(make_pair(tmp.first->left, tmp.second+tmp.first->left->val));
                }
                if(tmp.first->right) {
                    qu.push(make_pair(tmp.first->right, tmp.second+tmp.first->right->val));
                }
            }
        }
        return false;
    }
};
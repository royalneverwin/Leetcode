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
    int maxDepth(TreeNode* root) {
        int ret = 0;
        if(root == nullptr)
            return ret;
        queue<pair<TreeNode *, int>> qu;
        ret = 1;
        if(root->left != nullptr)
            qu.push(make_pair(root->left, 2));
        if(root->right != nullptr)
            qu.push(make_pair(root->right, 2));

        while(!qu.empty()) {
            pair<TreeNode *, int> tmp = qu.front();
            qu.pop();
            ret = max(tmp.second, ret);
            if(tmp.first->left != nullptr)
                qu.push(make_pair(tmp.first->left, tmp.second + 1));
            if(tmp.first->right != nullptr)
                qu.push(make_pair(tmp.first->right, tmp.second + 1));
        }
        return ret;
    }
};
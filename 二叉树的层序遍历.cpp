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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans = vector<vector<int>>();
        if(root == nullptr)
            return ans;
        queue<pair<TreeNode *, int>> qu;
        qu.push(make_pair(root->left, 1));
        qu.push(make_pair(root->right, 1));
        ans.push_back(vector<int>());
        ans[0].push_back(root->val);
        int layer = 0;
        while(!qu.empty()) {
            pair<TreeNode *, int> tmp = qu.front();
            qu.pop();
            if(tmp.first != nullptr) {
                if(layer < tmp.second) {
                    layer = tmp.second;
                    ans.push_back(vector<int>());
                }
                ans[layer].push_back(tmp.first->val);
                qu.push(make_pair(tmp.first->left, tmp.second + 1));
                qu.push(make_pair(tmp.first->right, tmp.second + 1));
            }
        }
        return ans;


    }
};
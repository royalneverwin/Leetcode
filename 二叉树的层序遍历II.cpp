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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) {
            return vector<vector<int>>();
        }
        vector<vector<TreeNode *>> layers;
        int curLayer = 0;
        layers.emplace_back(vector<TreeNode *>());
        queue<pair<TreeNode *, int>> qu;
        qu.push(make_pair(root, 0));
        while(!qu.empty()) {
            pair<TreeNode *, int> tmp = qu.front();
            qu.pop();
            if(tmp.second > curLayer) {
                layers.emplace_back(vector<TreeNode *>());
                curLayer++;
            }
            layers[curLayer].emplace_back(tmp.first);
            if(tmp.first->left) {
                qu.push(make_pair(tmp.first->left, tmp.second + 1));
            }
            if(tmp.first->right) {
                qu.push(make_pair(tmp.first->right, tmp.second + 1));
            }
        }
        int l = layers.size();
        vector<vector<int>> ans(l, vector<int>());
        for(int i = 0; i < l; i++) {
            ans[i] = vector<int>(layers[l-i-1].size(), 0);
            for(int j = 0; j < layers[l-i-1].size(); j++) {
                ans[i][j] = layers[l-i-1][j]->val;
            }
        }
        return ans;
    }
};
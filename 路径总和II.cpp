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
    void DFS(TreeNode *root, int targetSum, int curSum, vector<vector<int>>& ans, vector<int>& cur) {
        if(!root->left && !root->right) {
            if(curSum + root->val == targetSum) {
                cur.push_back(root->val);
                ans.emplace_back(cur);
                cur.pop_back();
            }
        }
        else {
            cur.push_back(root->val);
            if(root->left) {
                DFS(root->left, targetSum, curSum+root->val, ans, cur);
            }
            if(root->right) {
                DFS(root->right, targetSum, curSum+root->val, ans, cur);
            }
            cur.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return vector<vector<int>>();
        vector<vector<int>> ans;
        vector<int> cur;
        DFS(root, targetSum, 0, ans, cur);
        return ans;
    }
};
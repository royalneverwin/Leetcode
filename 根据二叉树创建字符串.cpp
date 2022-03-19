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
    void dfs(TreeNode* root, string& ans, bool flag){
        if(root != nullptr){
            ans.append(to_string(root->val));
            if(root->left != nullptr){
                ans.append(1, '(');
                dfs(root->left, ans, 1);
            }
            else if(root->right != nullptr){
                ans.append("()");
            }
            if(root->right != nullptr){
                ans.append(1, '(');
                dfs(root->right, ans, 1);
            }
        }
        if(flag)
            ans.append(1, ')');
    }
    string tree2str(TreeNode* root) {
        string ans;
        dfs(root, ans, 0);
        return ans;
    }
};
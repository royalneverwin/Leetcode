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
    int val;
    bool judge(TreeNode *root){
        if(root == nullptr)
            return true;

        if(root->val == val)
            return judge(root->left) & judge(root->right);
        else
            return false;
    }

    bool isUnivalTree(TreeNode* root) {
        val = root->val;
        return judge(root->left) & judge(root->right);
    }
};
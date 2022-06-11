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
    int findSum(TreeNode *root, int prev) {
        if(root->left == nullptr && root->right == nullptr)
            return prev * 2 + root->val;
        else if(root->right == nullptr){
            return findSum(root->left, prev * 2 + root->val);
        }
        else if(root->left == nullptr) {
            return findSum(root->right, prev * 2 + root->val);
        }
        else{
            return findSum(root->left, prev * 2 + root->val) + findSum(root->right, prev * 2 + root->val);
        }

        return 0;
    }

    int sumRootToLeaf(TreeNode* root) {
        return findSum(root, 0);
    }
};
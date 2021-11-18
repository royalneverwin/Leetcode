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
 //递归
class Solution {
public:
    int findLength(TreeNode *root){
        if(root->left == NULL && root->right == NULL)
            return root->val;
        else if(root->left == NULL)
            return findLength(root->right) + root->val;
        else if(root->right == NULL)
            return findLength(root->left) + root->val;
        else
            return findLength(root->right) + findLength(root->left) + root->val;
    }
    int findTilt(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 0;
        else if(root->left == NULL)
            return abs(findLength(root->right)) + findTilt(root->right);
        else if(root->right == NULL)
            return abs(findLength(root->left)) + findTilt(root->left);
        else
            return abs(findLength(root->left) - findLength(root->right)) + findTilt(root->left)
                   + findTilt(root->right);
    }
};
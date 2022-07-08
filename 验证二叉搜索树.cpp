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
    bool isValidSubBST(TreeNode *root, long max, long min) {
        if(root->val <= min || root->val >= max)
            return false;
        if(root->left != nullptr) {
            if(root->val <= root->left->val)
                return false;
            if(!isValidSubBST(root->left, root->val, min))
                return false;
        }
        if(root->right != nullptr) {
            if(root->val >= root->right->val)
                return false;
            if(!isValidSubBST(root->right, max, root->val))
                return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root->left != nullptr) {
            if(root->val <= root->left->val)
                return false;
            if(!isValidSubBST(root->left, root->val, -(pow(2, 31) + 1)))
                return false;
        }
        if(root->right != nullptr) {
            if(root->val >= root->right->val)
                return false;
            if(!isValidSubBST(root->right, pow(2, 31) + 1, root->val))
                return false;
        }
        return true;
    }
};
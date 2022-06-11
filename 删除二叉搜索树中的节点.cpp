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
    // 递归
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *ret = root;
        TreeNode *prev = NULL;
        if(root == NULL)
            return ret;
        while(root->val != key) {
            if(root->val < key) {
                if(root->right == NULL)
                    return ret;
                else {
                    prev = root;
                    root = root->right;
                }
            }
            else if(root->val > key){
                if(root->left == NULL)
                    return ret;
                else {
                    prev = root;
                    root = root->left;
                }
            }
        }

        if(root->left == NULL) {
            if(root->right == NULL) {
                if(prev == NULL) {
                    return NULL;
                }
                if(root->val < prev->val) {
                    prev->left = NULL;
                }
                else {
                    prev->right = NULL;
                }
            }
            else {
                TreeNode *replace = root->right;
                while(replace->left != NULL) {
                    replace = replace->left;
                }
                if(prev == NULL) {
                    ret = replace;
                }
                else {
                    if(prev->val > replace->val) {
                        prev->left = replace;
                    }
                    else {
                        prev->right = replace;
                    }
                }
                replace->right = deleteNode(root->right, replace->val);
            }
        }
        else {
            TreeNode *replace = root->left;
            while(replace->right != NULL) {
                replace = replace->right;
            }
            if(prev == NULL) {
                ret = replace;
            }
            else {
                if(prev->val > replace->val) {
                    prev->left = replace;
                }
                else {
                    prev->right = replace;
                }
            }
            replace->left = deleteNode(root->left, replace->val);
            replace->right = root->right;

        }

        return ret;
    }
};
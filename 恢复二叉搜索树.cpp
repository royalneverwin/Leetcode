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
    TreeNode *prev;
    TreeNode *a;
    TreeNode *b;
    void FindWrong(TreeNode *root) {
        if(root->left != nullptr)
            FindWrong(root->left);
        if(prev != nullptr) {
            if(a == nullptr) {
                if(root->val < prev->val) {
                    a = prev;
                    b = root;
                }
            }
            else { // 找b
                if(root->val < prev->val) {
                    b = root;
                }
            }
        }
        prev = root;
        if(root->right != nullptr)
            FindWrong(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = nullptr;
        a = nullptr;
        b = nullptr;
        if(root->left != nullptr)
            FindWrong(root->left);
        if(prev != nullptr) {
            if(a == nullptr) {
                if(root->val < prev->val) {
                    a = prev;
                    b = root;
                }
            }
            else { // 找b
                if(root->val < prev->val) {
                    b = root;
                }
            }
        }
        prev = root;
        if(root->right != nullptr)
            FindWrong(root->right);
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
};
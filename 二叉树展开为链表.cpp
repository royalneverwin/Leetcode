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
    TreeNode *flattenWithNode(TreeNode *root) { // 返回展开root后的最后一个树
        if(root) {
            TreeNode *leftLast = flattenWithNode(root->left);
            TreeNode *rightLast;
            if(!leftLast) { // root没有左子树
                rightLast = flattenWithNode(root->right);
                if(!rightLast)
                    return root;
                else
                    return rightLast;
            }
            else {
                leftLast->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                rightLast = flattenWithNode(leftLast->right);
                if(!rightLast)
                    return leftLast;
                else
                    return rightLast;
            }
        }
        else {
            return nullptr;
        }
    }
    void flatten(TreeNode* root) {
        if(root)
            flattenWithNode(root);
    }
};
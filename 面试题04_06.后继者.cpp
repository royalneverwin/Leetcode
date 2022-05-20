/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root->val < p->val){
            if(root->right == NULL)
                return NULL;

            return inorderSuccessor(root->right, p);
        }
        else if(root->val == p->val){
            root = root->right;
            if(root == NULL)
                return NULL;

            while(root->left != NULL)
                root = root->left;

            return root;

        }
        else{
            if(root->left == NULL)
                return root;

            TreeNode *left = root->left;
            while(left->right != NULL)
                left = left->right;

            if(left->val <= p->val)
                return root;
            else
                return inorderSuccessor(root->left, p);
        }
    }
};
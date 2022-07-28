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
class CBTInserter {
    TreeNode *rt;
public:
    CBTInserter(TreeNode* root) {
        rt = root;
    }

    int insert(int val) {
        queue<TreeNode *> qu;
        qu.push(rt);
        while(1) {
            TreeNode *tmp = qu.front();
            qu.pop();
            if(tmp->left == nullptr) {
                TreeNode *newt = new TreeNode;
                newt->val = val;
                newt->left = newt->right = nullptr;
                tmp->left = newt;
                return tmp->val;
            }
            else if(tmp->right == nullptr) {
                TreeNode *newt = new TreeNode;
                newt->val = val;
                newt->left = newt->right = nullptr;
                tmp->right = newt;
                return tmp->val;
            }
            else {
                qu.push(tmp->left);
                qu.push(tmp->right);
            }
        }
    }

    TreeNode* get_root() {
        return rt;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
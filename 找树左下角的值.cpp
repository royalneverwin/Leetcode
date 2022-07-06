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
    int findBottomLeftValue(TreeNode* root) {
        queue<tuple<TreeNode *, int>> myqu;
        myqu.push(tuple(root, 0));
        int curLayer = 0;
        int curVal = root->val;
        while(!myqu.empty()) {
            TreeNode *tmp;
            int layer;
            tie(tmp, layer) = myqu.front();
            myqu.pop();
            if(layer > curLayer) {
                curLayer = layer;
                curVal = tmp->val;
            }
            if(tmp->left != nullptr) {
                myqu.push(tuple(tmp->left, layer+1));
            }
            if(tmp->right != nullptr) {
                myqu.push(tuple(tmp->right, layer+1));
            }
        }

        return curVal;

    }
};
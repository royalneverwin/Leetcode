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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode *newn = new TreeNode(val, root, nullptr);
            return newn;
        }
        else {
            queue<pair<TreeNode*, int>> qu;
            qu.push(make_pair(root, 1));
            while(!qu.empty()) {
                pair<TreeNode*, int> tmp = qu.front();
                qu.pop();
                if(tmp.second == depth-1) {
                    TreeNode *newL = new TreeNode(val, tmp.first->left, nullptr);
                    TreeNode *newR = new TreeNode(val, nullptr, tmp.first->right);
                    tmp.first->left = newL;
                    tmp.first->right = newR;
                }
                else {
                    if(tmp.first->left)
                        qu.push(make_pair(tmp.first->left, tmp.second+1));
                    if(tmp.first->right)
                        qu.push(make_pair(tmp.first->right, tmp.second+1));
                }
            }
            return root;
        }
    }
};
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
            return ans;
        int prev = -1;
        queue<tuple<TreeNode *, int>> myqu;
        myqu.push(tuple(root, 0));
        TreeNode *tmp;
        int layer;
        while(!myqu.empty()) {
            tie(tmp, layer) = myqu.front();
            myqu.pop();

            if(layer > prev) {
                prev = layer;
                ans.push_back(tmp->val);
            }
            else {
                ans[layer] = max(ans[layer], tmp->val);
            }

            if(tmp->left) {
                myqu.push(tuple(tmp->left, layer+1));
            }
            if(tmp->right) {
                myqu.push(tuple(tmp->right, layer+1));
            }
        }

        return ans;
    }
};
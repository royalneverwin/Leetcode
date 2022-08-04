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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode *, int>> qu;
        qu.push(make_pair(root, 1));
        int layer = 1;
        int sum = 0;
        int ansLayer = 0;
        int maxSum = -1000000000;
        while(!qu.empty()) {
            pair<TreeNode *, int> tmp = qu.front();
            qu.pop();
            if(tmp.second == layer) {
                sum += tmp.first->val;
            }
            else {
                if(sum > maxSum) {
                    ansLayer = layer;
                    maxSum = sum;
                }
                layer++;
                sum = tmp.first->val;
            }
            if(tmp.first->left) {
                qu.push(make_pair(tmp.first->left, tmp.second + 1));
            }
            if(tmp.first->right) {
                qu.push(make_pair(tmp.first->right, tmp.second + 1));
            }
        }

        if(sum > maxSum) {
            ansLayer = layer;
            maxSum = sum;
        }

        return ansLayer;
    }
};
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans = vector<vector<int>>();
        if(root == nullptr)
            return ans;
        stack<pair<TreeNode *, int>> st1;
        stack<pair<TreeNode *, int>> st2;
        int layer = 0;
        ans.push_back(vector<int>());
        ans[layer].push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
            return ans;
        if(root->left != nullptr)
            st1.push(make_pair(root->left, 1));
        if(root->right != nullptr)
            st1.push(make_pair(root->right, 1));
        layer += 1;
        ans.push_back(vector<int>());
        while(!st1.empty() || !st2.empty()) {
            pair<TreeNode *, int> tmp;
            if(layer % 2 != 0 && st1.empty()) {
                ans.push_back(vector<int>());
                layer++;
            }
            else if(layer % 2 == 0 && st2.empty()) {
                ans.push_back(vector<int>());
                layer++;
            }
            if(layer % 2 != 0) {
                tmp = st1.top();
                st1.pop();
            }
            else {
                tmp = st2.top();
                st2.pop();
            }

            if(tmp.first != nullptr) {
                ans[layer].push_back(tmp.first->val);
                if(layer % 2 == 0) {
                    if(tmp.first->left != nullptr)
                        st1.push(make_pair(tmp.first->left, tmp.second + 1));
                    if(tmp.first->right != nullptr)
                        st1.push(make_pair(tmp.first->right, tmp.second + 1));
                }
                else {
                    if(tmp.first->right != nullptr)
                        st2.push(make_pair(tmp.first->right, tmp.second + 1));
                    if(tmp.first->left != nullptr)
                        st2.push(make_pair(tmp.first->left, tmp.second + 1));
                }
            }
        }

        return ans;

    }
};
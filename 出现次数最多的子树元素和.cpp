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
    unordered_map<int, int> cnt;
    int GetVal(TreeNode *root) {
        int ret;
        if(root->left ==NULL && root->right == NULL) {
            ret = root->val;
        }
        else if(root->left == NULL) {
            ret = root->val + GetVal(root->right);
        }
        else if(root->right == NULL) {
            ret = root->val + GetVal(root->left);
        }
        else {
            ret = root->val + GetVal(root->right) + GetVal(root->left);
        }

        cnt[ret]++;
        return ret;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        GetVal(root);
        vector<int> ans;
        int retCnt = 0;
        for(auto &i: cnt) {
            if(i.second > retCnt) {
                ans.clear();
                retCnt = i.second;
                ans.push_back(i.first);
            }
            else if(i.second == retCnt) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
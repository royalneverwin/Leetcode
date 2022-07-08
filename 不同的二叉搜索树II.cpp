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
    vector<TreeNode*> generateSubTrees(int begin, int end) {
        vector<TreeNode*> ret = vector<TreeNode*>();
        if(end < begin) {
            ret.emplace_back(nullptr);
            return ret;
        }

        for(int i = begin; i <= end; i++) {
            vector<TreeNode*> lefts = generateSubTrees(begin, i-1);
            vector<TreeNode*> rights = generateSubTrees(i+1, end);
            for(int j = 0; j < lefts.size(); j++) {
                for(int k = 0; k < rights.size(); k++) {
                    TreeNode *tmp = new TreeNode;
                    tmp->val = i;
                    tmp->left = lefts[j];
                    tmp->right = rights[k];
                    ret.emplace_back(tmp);
                }
            }
        }

        return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateSubTrees(1, n);
    }
};
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
    void bfs(TreeNode* root, unordered_set<int>& hash, vector<int>& num){
        if(root != nullptr){
            bfs(root->left, hash, num);
            hash.insert(root->val);
            num.emplace_back(root->val);
            bfs(root->right, hash, num);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> hash;
        vector<int> num;
        bfs(root, hash, num);
        for(int i = 0; i < num.size(); i++){
            if( k != num[i] * 2 && hash.count(k - num[i]))
                return true;
        }
        return false;
    }
};
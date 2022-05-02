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
    void Search(TreeNode *root, vector<int>& num){
        if(root == nullptr)
            return;

        if(root->left != nullptr)
            Search(root->left, num);

        num.push_back(root->val);

        if(root->right != nullptr)
            Search(root->right, num);
    }

    void Merge(vector<int>& num1, vector<int>& num2, vector<int>& num){
        int index1 = 0, index2 = 0;
        while(index1 < num1.size() && index2 < num2.size()){
            if(num1[index1] <= num2[index2]){
                num.push_back(num1[index1]);
                index1++;
            }
            else{
                num.push_back(num2[index2]);
                index2++;
            }
        }

        while(index1 < num1.size()){
            num.push_back(num1[index1]);
            index1++;
        }

        while(index2 < num2.size()){
            num.push_back(num2[index2]);
            index2++;
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> num1;
        vector<int> num2;
        Search(root1, num1);
        Search(root2, num2);

        vector<int> ans;

        Merge(num1, num2, ans);
        return ans;
    }
};
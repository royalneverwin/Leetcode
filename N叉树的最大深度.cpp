/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        return dfs(root);
    }
    int dfs(Node* root){
        int ret = 0;
        if(root == nullptr)
            return 0;
        int length = root->children.size();
        for(int i = 0; i < length; i++)
            ret = max(dfs(root->children[i]), ret);
        return ret + 1;
    }
};
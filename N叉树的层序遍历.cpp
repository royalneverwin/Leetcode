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
    typedef pair<Node *, int> pair;
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        queue<pair> myqu;
        myqu.push(make_pair(root, 0));
        int curLayer = 0;
        vector<int> curVec;
        while(!myqu.empty()){
            pair tmp = myqu.front();
            myqu.pop();
            if(tmp.second != curLayer){
                ans.emplace_back(curVec);
                curVec.clear();
                curVec.push_back((tmp.first->val));
                curLayer++;
            }
            else
                curVec.push_back((tmp.first)->val);

            for(int i = 0; i < ((tmp.first)->children).size(); i++){
                myqu.push(make_pair(((tmp.first)->children)[i], curLayer+1));
            }
        }
        ans.emplace_back(curVec);

        return ans;
    }
};
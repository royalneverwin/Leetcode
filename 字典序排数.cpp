class Solution {
public:
    // 字典树
    void dicTree(vector<int>& ans, int cur, int n){
        ans.push_back(cur);
        for(int i = 0; i <= 9; i++){
            if(cur * 10 + i <= n)
                dicTree(ans, cur *10 + i, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i <= min(9, n); i++){
            dicTree(ans, i, n);
        }
        return ans;
    }
};
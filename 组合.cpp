class Solution {
public:
    vector<vector<int>> ans;
    void bfs(vector<int>& cur, int n, int begin, int left){
        if(left == 0){
            ans.emplace_back(cur);
            return;
        }
        if(n - begin + 1 > left){
            bfs(cur, n, begin+1, left);
        }
        cur.push_back(begin);
        bfs(cur, n, begin+1, left-1);
        cur.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        bfs(cur, n, 1, k);
        return ans;
    }
};
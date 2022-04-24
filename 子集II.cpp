class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& cur, vector<int>& cnt, int index){
        if(index == cnt.size()){
            ans.emplace_back(cur);
            return;
        }

        dfs(ans, cur, cnt, index+1);
        for(int i = 1; i <= cnt[index]; i++){
            cur.push_back(index-10);
            dfs(ans, cur, cnt, index+1);
        }
        for(int i = 1; i <= cnt[index]; i++)
            cur.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cnt(21, 0);
        vector<vector<int>> ans;
        vector<int> cur;

        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i] + 10]++;
        }

        dfs(ans, cur, cnt, 0);
        return ans;
    }
};
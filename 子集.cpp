class Solution {
public:
    vector<vector<int>> ans;
    void bfs(vector<int>& cur, vector<int>& nums, int begin){
        if(begin == nums.size()){
            ans.emplace_back(cur);
            return;
        }
        bfs(cur, nums, begin+1);
        cur.push_back(nums[begin]);
        bfs(cur, nums, begin+1);
        cur.pop_back();


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        bfs(cur, nums, 0);
        return ans;
    }
};
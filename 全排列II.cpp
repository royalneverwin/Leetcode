class Solution {
public:
    // 回溯法
    void TraceBack(vector<vector<int>>& ans, vector<int>& nums, int index){ // 从0开始
        if(index == nums.size()){
            // if(find(ans.begin(), ans.end(), nums) == ans.end())
            ans.push_back(nums);
        }
        else{
            int tmp;
            bool flag[21];
            memset(flag, 0, sizeof(flag));
            for(int i = index; i < nums.size(); i++){
                if(!flag[nums[i] + 10]){
                    flag[nums[i] + 10] = true;
                    tmp = nums[index];
                    nums[index] = nums[i];
                    nums[i] = tmp;
                    TraceBack(ans, nums, index+1);
                    // 回溯
                    tmp = nums[index];
                    nums[index] = nums[i];
                    nums[i] = tmp;
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        TraceBack(ans, nums, 0);
        return ans;
    }
};
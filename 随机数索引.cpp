class Solution {
    unordered_map<int, vector<int>> mmap;
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(!mmap.count(nums[i])){
                vector<int> tmp = {i};
                mmap[nums[i]] = tmp;
            }
            else{
                mmap[nums[i]].push_back(i);
            }
        }
    }

    int pick(int target) {
        return mmap[target][rand() % mmap[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
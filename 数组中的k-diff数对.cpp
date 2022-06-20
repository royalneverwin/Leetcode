class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> check;
        unordered_set<int> res; // 避免重复

        for(size_t i = 0; i < nums.size(); i++) {
            if(check.count(nums[i] - k))
                res.emplace(nums[i] - k);
            if(check.count(nums[i] + k))
                res.emplace(nums[i]);
            check.emplace(nums[i]);
        }

        return res.size();
    }
};
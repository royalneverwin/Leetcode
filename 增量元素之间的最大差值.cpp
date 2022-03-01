class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        vector<int> minOne(nums.size(), 0); // 0到i中最小的
        vector<int> maxOne(nums.size(), 0); // i到结尾中最大的

        minOne[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > minOne[i-1])
                minOne[i] = minOne[i-1];
            else
                minOne[i] = nums[i];
        }
        maxOne[nums.size()-1] = nums[nums.size()-1];
        for(int j = nums.size()-2; j >= 0; j--){
            if(nums[j] < maxOne[j+1])
                maxOne[j] = maxOne[j+1];
            else
                maxOne[j] = nums[j];
        }

        int ans = -1;
        for(int i = 0; i < nums.size()-1; i++){
            if(maxOne[i+1] > minOne[i])
                ans = max(ans, maxOne[i+1] - minOne[i]);
        }
        return ans;
    }
};
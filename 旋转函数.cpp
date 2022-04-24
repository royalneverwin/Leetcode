class Solution {
public:
    int maxRotateFunction(vector<int>& nums) { // 遍历
        int length = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        for(int i = 0; i < length; i++)
            ans += i * nums[i];

        int curSum = ans;
        for(int i = length-1; i >= 0; i--){
            curSum = curSum - (length-1) * nums[i] + sum - nums[i];
            ans = max(ans, curSum);
        }
        return ans;
    }
};
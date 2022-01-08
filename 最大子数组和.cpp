class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        int dp[length]; // 从i开始的最大和
        memset(dp, 0, sizeof(dp));
        int ans = nums[length - 1];
        dp[length - 1] = nums[length - 1];
        for(int i = length - 2; i >= 0; i--){
            if(dp[i + 1] > 0){
                dp[i] = dp[i + 1] + nums[i];
            }
            else{
                dp[i] = nums[i];
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size();
        int dp[length]; // 从length跳到最后一个未知的最少次数, -1表示不可能
        memset(dp, 0, sizeof(dp));
        dp[length-1] = 0;
        for(int i = length-2; i >= 0; i--){
            if(nums[i] == 0)
                dp[i] = -1;
            else{
                int tmp = length+1;
                int maxj = min(nums[i], length - i - 1);
                for(int j = 1; j <= maxj; j++){
                    if(dp[i+j] != -1)
                        tmp = min(dp[i+j], tmp);
                }
                if(tmp == length+1)
                    dp[i] = -1;
                else
                    dp[i] = tmp + 1;
            }
        }
        return dp[0];
    }
};
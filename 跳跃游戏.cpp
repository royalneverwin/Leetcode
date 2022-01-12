class Solution {
public:
    // 简单动归
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        bool bp[length];
        memset(bp, 0, sizeof(bp));
        bp[length - 1] = true;
        for(int i = length - 2; i >= 0; i--){
            for(int j = 1; j <= nums[i]; j++){
                if(bp[i + j]){
                    bp[i] = true;
                    break;
                }
            }
        }
        return bp[0];
    }
};


class Solution {
public:
    // 贪心
    // 如果我能到位置i, 我一定能到位置i前面所有的位置（位置i是最远距离, 我只要减少跳跃距离, 就能到位置i之前的位置）
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        int length = nums.size();
        for(int i = 0; i <= maxIndex; i++){ // 我最多只能到maxIndex, 后面的不用看了
            maxIndex = max(maxIndex, i + nums[i]);
            if(maxIndex >= length - 1)
                return true;
        }
        return false;
    }
};
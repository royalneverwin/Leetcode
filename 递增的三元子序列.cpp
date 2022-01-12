class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int length = nums.size();
        int minN = nums[0];
        bool flag = false;
        int minNext; // 记录所有第二大数的最小值
        for(int i = 1; i < length; i++){
            if(flag){
                if(nums[i] > minNext)
                    return true;
            }
            minN  = min(minN, nums[i]);
            if(nums[i] > minN){
                if(!flag){
                    flag = true;
                    minNext = nums[i];
                }
                else{
                    minNext = min(minNext, nums[i]);
                }
            }
        }
        return false;
    }
};
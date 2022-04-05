class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 双指针
        int slow = 1, fast = 1;
        int pre = nums[0];
        int cnt = 1;
        for(; fast < nums.size(); fast++){
            if(nums[fast] != pre){
                nums[slow] = nums[fast];
                pre = nums[fast];
                slow++;
                cnt = 1;
            }
            else if(cnt < 2){
                cnt++;
                nums[slow] = pre;
                slow++;
            }
        }
        return slow;
    }
};
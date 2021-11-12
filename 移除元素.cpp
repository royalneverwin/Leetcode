//双指针！
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        for(; fast < nums.size(); fast++){
            if(nums[fast] != val){
                if(slow != fast)
                    nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
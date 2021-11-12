//遍历就想双指针！+ 避免原地赋值
//前提：有序数组
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        for(; fast < nums.size(); fast++){
            if(fast == 0 || nums[fast-1] != nums[fast]){
                if(fast != slow)
                    nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

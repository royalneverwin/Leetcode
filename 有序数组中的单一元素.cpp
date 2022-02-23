class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while(right > left){
            middle = (left + right) / 2;
            if(nums[middle-1] == nums[middle]){
                if(((right - left) / 2) % 2 == 0){ // 子数组长度是偶数
                    right = middle-2;
                }
                else{ // 子数组长度是奇数
                    left = middle+1;
                }
            }
            else if(nums[middle+1] == nums[middle]){
                if(((right - left) / 2) % 2 == 0){ // 子数组长度是偶数
                    left = middle+2;
                }
                else{ // 子数组长度是奇数
                    right = middle-1;
                }
            }
            else{
                return nums[middle];
            }
        }
        return nums[left];
    }
};
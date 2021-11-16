//二分
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) / 2;
        while(nums[middle] != target){
            if(nums[middle] < target){
                left = middle + 1;
                if(left > right){
                    return left;
                }
            }
            else{
                right = middle - 1;
                if(right < left){
                    return left;
                }
            }
            middle = (left + right) / 2;
        }
        return middle;
    }
};
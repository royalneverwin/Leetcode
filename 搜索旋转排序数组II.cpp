class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums[0] < target){
            for(int i = 0; i < nums.size()-1; i++){
                if(nums[i] == target)
                    return true;
                else if(nums[i] > target)
                    return false;
                else if(nums[i+1] < nums[i]) // 遍历完了
                    return false;
            }
            if(nums[nums.size()-1] == target)
                return true;
            else
                return false;
        }
        else if(nums[0] > target){
            for(int i = nums.size() - 1; i >= 1; i--){
                if(nums[i] == target)
                    return true;
                else if(nums[i] < target)
                    return false;
                else if(nums[i-1] > nums[i]) // 遍历完了
                    return false;
            }
            return false;
        }
        else{
            return true;
        }
    }
};
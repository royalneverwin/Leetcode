//二分
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size() == 0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int left = 0;
        int right = nums.size() - 1;
        int middle = (left + right) / 2;
        int ans1, ans2;
        while(nums[middle] != target){
            if(nums[middle] > target){
                right = middle - 1;
                if(right < left){ //not in nums
                    ans.push_back(-1);
                    ans.push_back(-1);
                    return ans;
                }
            }
            else{
                left = middle + 1;
                if(left > right){ //not in nums
                    ans.push_back(-1);
                    ans.push_back(-1);
                    return ans;
                }
            }
            middle = (left + right) / 2;
        }
        // now we know that ans1 <= middle, ans2 >= middle, binary sort again
        left = 0;
        right = middle;
        ans1 = (left + right) / 2;
        while(1){
            if(nums[ans1] == target){
                if(right == ans1){ //there must be left == right
                    break;
                }
                right = ans1;
            }
            else if(nums[ans1] < target){
                left = ans1 + 1;
            }
            ans1 = (left + right) / 2;
        }
        left = middle;
        right = nums.size() - 1;
        ans2 = (left + right) / 2;
        while(1){
            if(nums[ans2] == target){
                if(left == ans2){
                    //judge whether nums[right] == target
                    if(left != right && nums[ans2+1] == target)
                        ans2++;
                    break;
                }
                left = ans2;
            }
            else if(nums[ans2] > target){
                right = ans2 - 1;
            }
            ans2 = (left + right) / 2;
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};
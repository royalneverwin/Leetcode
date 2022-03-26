class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        for(int i = 1; i < nums.size()-1; i++){
            int left, right;
            for(left = i-1; left >= 0; left--){
                if(nums[left] != nums[i])
                    break;
            }
            for(right = i+1; right < nums.size(); right++){
                if(nums[right] != nums[i])
                    break;
            }
            if(left == -1 || right == nums.size())
                continue;
            else if(nums[left] > nums[i] && nums[right] < nums[i])
                continue;
            else if(nums[left] < nums[i] && nums[right] > nums[i])
                continue;
            else if(nums[left] > nums[i] && nums[right] > nums[i]){
                i = right-1;
                ans++;
            }
            else if(nums[left] < nums[i] && nums[right] < nums[i]){
                i = right-1;
                ans++;
            }
        }
        return ans;
    }
};
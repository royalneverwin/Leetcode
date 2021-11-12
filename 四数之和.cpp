//same as 三数之和，没什么好说的...

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if(nums.size() < 4){
            return ans;
        }
        int prev;
        for(int i = 0; i < nums.size() - 3; i++){
            if(i != 0 && nums[i] == prev){
                continue;
            }
            else {
                prev = nums[i];
                int prevj;
                for (int j = i + 1; j < nums.size() - 2; j++) {
                    if(j != i+1 && nums[j] == prevj){
                        continue;
                    }
                    else {
                        prevj = nums[j];
                        int tmp = target - nums[i] - nums[j];
                        int left = j + 1;
                        int right = nums.size() - 1;
                        while (left < right) {
                            if (nums[left] + nums[right] == tmp) {
                                vector<int> oneAns;
                                oneAns.push_back(nums[i]);
                                oneAns.push_back(nums[j]);
                                oneAns.push_back(nums[left]);
                                oneAns.push_back(nums[right]);
                                ans.push_back(oneAns);
                                while(left + 1 < right && nums[left+1] == nums[left]){
                                    left++;
                                }
                                left++;
                            } else {
                                if (nums[left] + nums[right] > tmp) {
                                    while(right - 1 > left && nums[right-1] == nums[right]){
                                        right--;
                                    }
                                    right--;
                                } else {
                                    while(left + 1 < right && nums[left+1] == nums[left]){
                                        left++;
                                    }
                                    left++;
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
//双指针就vans了，学以致用，学以致用
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int dis = 100000;
        int ans = -1;
        for(int i = 0; i < nums.size()-2; i++){
            int left = i+1;
            int right = nums.size() - 1;
            int sum;
            while(left < right){
                sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < dis){
                    ans = sum;
                    dis = abs(sum - target);
                }
                //cout << ans << ' ' << nums[i] << ' ' << nums[left] << ' ' << nums[right] << endl;
                if(sum == target){
                    return target;
                }
                else if(sum < target){
                    while(left+1 < right && nums[left+1] == nums[left])
                        left++;
                    left++;
                }
                else{
                    while(right-1 > left && nums[right-1] == nums[right])
                        right--;
                    right--;
                }
            }
        }
        return ans;
    }
};
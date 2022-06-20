class Solution {
public:
    int F(vector<int>& nums, int dis) { // 双指针
        int left = 0, right = 0;
        int ret = 0;
        while(left < nums.size()) {
            while(right < nums.size() && nums[right] - nums[left] <= dis) {
                right++;
            }
            ret += right - left - 1;
            left++;
            while(left < nums.size() && nums[right] - nums[left] > dis) {
                ret += right - left - 1;
                left++;
            }
        }

        return ret;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[nums.size()-1] - nums[0];
        while(left < right) { // 二分查找
            int mid = left + (right - left) / 2;
            if(F(nums, mid) < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};
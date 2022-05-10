class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int ans = 0;
        int left = 0, right = 0;
        int sum = 1;
        while(left < nums.size()){
            while(right < nums.size() && sum * nums[right] < k){
                sum = sum * nums[right];
                right++;
            }


            ans += right - left;

            if(sum > 1)
                sum /= nums[left];

            left++;
            while(sum >= k && sum != 1){ // 回溯right 特判k = 1的情况
                sum /= nums[right];
                right--;
            }

            if(right < left)
                right = left;
        }

        return ans;
    }
};
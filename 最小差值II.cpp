class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        // 排序
        // 若A[i] < A[j], 且A[i] 和 A[j] 同方向变化分数最小
        // 则A[i] 和 A[j]之间的数也必定按照同一方向变化
        // 而且若A[i] < A[j], 则不可能A[i]减少，A[j] 增大
        // 综上 一定有
        // 排序后前一部分全部增大 后一部分全部减少
        //若j是第一个减少的, 那么最小值只能是A[0]+k和A[j]-k之一，最大值只能是A[N-1]-k和A[j-1]+k之一
        sort(nums.begin(), nums.end());
        int ans = nums[nums.size()-1] - nums[0];
        for(int i = 0; i < nums.size()-1; i++){
            int minOne = min(nums[0] + k, nums[i+1] - k);
            int maxOne = max(nums[nums.size()-1] - k, nums[i] + k);
            ans = min(ans, maxOne - minOne);
        }

        return ans;
    }
};
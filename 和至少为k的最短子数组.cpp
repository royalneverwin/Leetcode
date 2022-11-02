class Solution {
public:
    // 添加负数之后窗口的滑动就没有单向性了 所以无法使用滑动窗口解决
    // 可以存前缀和（就是前i个数的和）
    // 存一个单增的前缀和，单增的原因：如果preSum[s2] <= preSum[s1]，那么如果有preSum[s3] - preSum[s1] >= k，就一定
    // 有preSum[s3] - preSum[s2] >= k且更短，所以可以忽略s1，只要存s2就行
    // 这样复杂度可以到O(n) 
    // deque 双端队列
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long, int>> preSum{make_pair(0, -1)};
        long sum = 0;
        int idx = 0;
        int res = nums.size()+1;
        while(idx < nums.size()) {
            sum += nums[idx];
            while (!preSum.empty() && sum - preSum.front().first >= k) {
                res = min(res, idx - preSum.front().second);
                preSum.pop_front();
            }
            while (!preSum.empty() && preSum.back().first >= sum) {
                preSum.pop_back();
            }
            preSum.push_back(make_pair(sum, idx));
            idx += 1;
        }
        return  res != nums.size()+1 ? res : -1;
    }
};
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        // 折半搜索
        // sum_a / num_a = sum_b / n - num_a, sum_a / num_a = num / n
        // 所以找均值 = num均值即可
        // 把nums每个元素 - 均值，则找均值 = 0即可（简化）
        // 遍历所有的子集 找均值 = 0 但2^30会超时
        // 所以把nums分成两半A1 A2 从A1中找x 从A2中找-x 让和 = 0 如果有就return True 否则return False
        // 注意这里不能取所有的A1和所有的A2 否则B会为空
        // 为了防止均值为浮点数 先将nums所有元素 * n 这样就都是int
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        int m = n / 2;
        if (n == 1) return false;
        for(int &i: nums) i = i * n - sum;
        unordered_set<int> lsum;
        for(int i = 1; i < (1 << m); i++) {
            int curSum = 0;
            for(int j = 0; j < m; j++) {
                if(i & (1 << j)) curSum += nums[j];
            }
            if (curSum == 0) return true;
            lsum.emplace(curSum);
        }
        int rsum = accumulate(nums.begin()+n/2, nums.end(), 0);
        for(int i = 1; i < (1 << (n - m)); i++) {
            int curSum = 0;
            for(int j = m; j < n; j++) {
                if(i & (1 << (j - m))) curSum += nums[j];
            }
            if(curSum == 0) return true;
            if(lsum.count(-curSum) && curSum != rsum) {
                return true;
            }
        }
        return false;
    }
};
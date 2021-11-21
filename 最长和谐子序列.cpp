class Solution {
public:
    //正常遍历会超时, T(n) = O(n^2)
    //根据子序列的定义可知, 我们可以任意修改数组顺序便于找到最长
    //我们先把数组排序, 这样更容易找. 确定子序列的最后一个元素end, 遍历, 然后找符合和谐子序列的最小的begin
    //实际上begin最多遍历1次数组, 所以时间复杂度为O(n)
    //双指针法
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int end = 0;
        int begin = 0;
        int ans = 0;
        for(end = 0; end < nums.size(); end++){
            while(nums[end] - nums[begin] > 1)
                begin++;
            if(nums[end] != nums[begin])
                ans = max(ans, end - begin + 1);
        }
        return ans;
    }
};
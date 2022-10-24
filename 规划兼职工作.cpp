class Solution {
public:
    // dp
    // 先对startTime排序
    // 从后往前计算选startTime开始工作的最大profit
    // trick：用lower_bound在startTime中找所有可能的后继
    // 因为每次找要从所有后继中选最大的profit 时间复杂度O(n^2) 所以定义一个maxDp记录pos及之后最大的Dp 降低时间复杂度到O(n)
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, int>> sortStartTime(n, pair<int, int>());
        for(int i = 0; i < n; i++) {
            sortStartTime[i] = make_pair(i, startTime[i]);
        }
        sort(sortStartTime.begin(), sortStartTime.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;});
        vector<int> dp(n, 0);
        vector<int> maxDp(n, 0);
        dp[n-1] = profit[sortStartTime[n-1].first]; // 边界
        maxDp[n-1] = dp[n-1];
        for(int i = n-2; i >= 0; i--) {
            int maxProfit= 0;
            int pos = lower_bound(sortStartTime.begin(), sortStartTime.end(), make_pair(0, endTime[sortStartTime[i].first]), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;}) - sortStartTime.begin();
            if(pos < n) {
                maxProfit = maxDp[pos];
            }
            dp[i] = profit[sortStartTime[i].first] + maxProfit;
            maxDp[i] = max(dp[i], maxDp[i+1]);
        }
        return maxDp[0];
    }
};
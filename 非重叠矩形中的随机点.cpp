class Solution {
    vector<long> preSum;
    vector<vector<int>>& Rects;
    long total = 0;
    mt19937 gen{random_device{}()};
public:
    Solution(vector<vector<int>>& rects): Rects{rects} {
        size_t l = rects.size();
        preSum = vector<long>(l + 1, 0);
        long preOne = 0;
        for(size_t i = 0; i < l; i++) {
            long curOne = (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            preSum[i + 1] = preOne + curOne;
            preOne = preSum[i + 1];
        }
        total = preSum[l];
    }

    vector<int> pick() {
        uniform_int_distribution<long> dist (1, total);

        long curOne = dist(gen);


        int index = lower_bound(preSum.begin(), preSum.end(), curOne) - preSum.begin() - 1;
        curOne -= preSum[index] + 1;
        int yl = Rects[index][3] - Rects[index][1] + 1;
        int cx = curOne / yl;
        int cy = curOne % yl;

        return vector<int>{Rects[index][0] + cx, Rects[index][1] + cy};

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */


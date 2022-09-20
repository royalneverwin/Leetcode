class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        // 贪心
        int n = quality.size();
        vector<double> w_per_q(n, 0.0);
        for(int i = 0; i < n; i++) {
            w_per_q[i] = double(wage[i]) / quality[i];
        }
        // 记录
        class Point{
        public:
            double w_per_q;
            int idx;
            Point() {
                w_per_q = 0.0;
                idx = 0;
            }
            bool operator < (const Point& p) {
                return w_per_q < p.w_per_q;
            }
        };
        vector<Point> combineIdx(n, Point());
        for(int i = 0; i < n; i++) {
            combineIdx[i].w_per_q = w_per_q[i];
            combineIdx[i].idx = i;
        }
        sort(combineIdx.begin(), combineIdx.end());
        double res = 1e10;

        priority_queue<int> qualityList;
        int amount = 0;
        for(int i = k-1; i < n; i++) { // 遍历combineIdx
            if(k >= 2) {
                if(i == k-1) {
                    for(int j = 0; j < i; j++) { // 统计quality的个数
                        amount += quality[combineIdx[j].idx];
                        qualityList.push(quality[combineIdx[j].idx]);
                    }
                }
                else {
                    if(qualityList.top() > quality[combineIdx[i-1].idx]) {
                        amount -= qualityList.top();
                        amount += quality[combineIdx[i-1].idx];
                        qualityList.pop();
                        qualityList.push(quality[combineIdx[i-1].idx]);
                    }
                }
            }
            res = min(res, (amount + quality[combineIdx[i].idx]) * combineIdx[i].w_per_q);
        }
        return res;
    }
};
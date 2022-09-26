class Solution {
public:
#define MOD (1000000000 + 7)
    static bool cmp(pair<long long, int>& p1, pair<long long, int>& p2) {
        return p1.first < p2.first;
    }
    int rectangleArea(vector<vector<int>>& rectangles) {
        // 扫描线：每遇到一个长方形的左或右边就会改变扫描线的长度 最多改变2n次
        // 离散化：对于扫描线长度的计算 长方形的上下顶点将直线分为2n+1份，两条射线不考虑 剩下2n-1条线段 记录他们是否被覆盖和长度
        int n = rectangles.size();

        // 构造length
        vector<long long> ys(2*n, 0);
        for(int i = 0; i < n; i++) {
            ys[2*i] = rectangles[i][1];
            ys[2*i+1] =  rectangles[i][3];
        }
        sort(ys.begin(), ys.end());
        auto end_iter = unique(ys.begin(), ys.end());
        ys.erase(end_iter, ys.end());
        int m = ys.size();
        // length可以通过ys相减得到
        vector<int> segCnt(m-1, 0);

        // 记录从左到右的矩形边界 记录的同时要记录对应的rectangle是哪一个（右边界还是左边界比一下就知道了）
        vector<pair<long long, int>> bound;
        for(int i = 0; i < n; i++) {
            bound.emplace_back(make_pair(rectangles[i][0], i));
            bound.emplace_back(make_pair(rectangles[i][2], i));
        }
        sort(bound.begin(), bound.end(), cmp);
        // 从左到右进行扫描 记得同一个横坐标的要一起扫描 不然一个个扫描会产生累加效果
        long long res = 0;
        for(int i = 0; i < 2*n; i++) {
            int j = i+1;
            long long x = bound[i].first;
            while(j < 2*n) {
                if(bound[j].first == x)
                    j++;
                else
                    break;
            }
            if(j == 2*n) // 已经结束了
                break;
            for(int k = i; k < j; k++) {
                int idx = bound[k].second;
                if(x == rectangles[idx][0] && x == rectangles[idx][2]) { // 特殊情况！矩形只是一条垂直x轴的线！
                    continue;
                }
                if(x == rectangles[idx][0]) { // 左边 seg+
                    for(int l = 0; l < m-1; l++) {
                        if(ys[l] >= rectangles[idx][1] && ys[l+1] <= rectangles[idx][3]) {
                            segCnt[l]++;
                        }
                    }
                }
                else { // 右边 seg-
                    for(int l = 0; l < m-1; l++) {
                        if(ys[l] >= rectangles[idx][1] && ys[l+1] <= rectangles[idx][3]) {
                            segCnt[l]--;
                        }
                    }
                }
            }
            for(int k = 0; k < m-1; k++) {
                if(segCnt[k] > 0) {
                    res += (ys[k+1] - ys[k]) * (bound[j].first - x);
                }
            }
            i = j-1;
        }
        return res % MOD;

    }
};
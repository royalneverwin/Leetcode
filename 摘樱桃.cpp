class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // 难的不谈
        // 可以把往返看作都是去
        // 要判断两个去是否经过了同一点（不能摘两次）
        // 所以让两次同时出发 这样方便判断是否经过了同一点
        // 用dp[k][x1][x2]表示，其中k是走的总路程 所以坐标分别是(x1, k-x1), (x2, k-x2)
        // BFS会超时 （我日你的哥 所有样例都过了 但是超时 所以我改变了一下if的顺序 勉强才过 吗的）
        int n = grid.size();
        int dp[2*(n+1)][n+1][n+1];
        memset(dp, 0xff, sizeof(dp));
        dp[0][0][0] = grid[0][0];
        // 有4种情况 分别带入
        queue<tuple<int, int, int, int>> myqu;
        myqu.push(make_tuple(0, 0, 0, grid[0][0]));
        int k, x1, x2, ret;
        while(!myqu.empty()) {
            tie(k, x1, x2, ret) = myqu.front();
            myqu.pop();
            // 4种可能
            if(k-x1+1 < n && x2+1 < n && grid[x1][k-x1+1] != -1 && grid[x2+1][k-x2] != -1) {
                if(x1 != x2+1) {
                    if(ret + grid[x1][k-x1+1] + grid[x2+1][k-x2] > dp[k+1][x1][x2+1]) {
                        dp[k+1][x1][x2+1] = ret + grid[x1][k-x1+1] + grid[x2+1][k-x2];
                        myqu.push(make_tuple(k+1, x1, x2+1, dp[k+1][x1][x2+1]));
                    }
                }
                else {
                    if(ret + grid[x1][k-x1+1] > dp[k+1][x1][x2+1]) {
                        dp[k+1][x1][x2+1] = ret + grid[x1][k-x1+1];
                        myqu.push(make_tuple(k+1, x1, x2+1, dp[k+1][x1][x2+1]));
                    }
                }
            }
            if(x1+1 < n && k-x2+1 < n && grid[x1+1][k-x1] != -1 && grid[x2][k-x2+1] != -1) {
                if(x1+1 != x2) {
                    if(ret + grid[x1+1][k-x1] + grid[x2][k-x2+1] > dp[k+1][x1+1][x2]) {
                        dp[k+1][x1+1][x2] = ret + grid[x1+1][k-x1] + grid[x2][k-x2+1];
                        myqu.push(make_tuple(k+1, x1+1, x2, dp[k+1][x1+1][x2]));
                    }
                }
                else {
                    if(ret + grid[x1+1][k-x1] > dp[k+1][x1+1][x2]) {
                        dp[k+1][x1+1][x2] = ret + grid[x1+1][k-x1];
                        myqu.push(make_tuple(k+1, x1+1, x2, dp[k+1][x1+1][x2]));
                    }
                }
            }
            if(x1+1 < n && x2+1 < n && grid[x1+1][k-x1] != -1 && grid[x2+1][k-x2] != -1) {
                if(x1 != x2) {
                    if(ret + grid[x1+1][k-x1] + grid[x2+1][k-x2] > dp[k+1][x1+1][x2+1]) {
                        dp[k+1][x1+1][x2+1] = ret + grid[x1+1][k-x1] + grid[x2+1][k-x2];
                        myqu.push(make_tuple(k+1, x1+1, x2+1, dp[k+1][x1+1][x2+1]));
                    }
                }
                else {
                    if(ret + grid[x1+1][k-x1] > dp[k+1][x1+1][x2+1]) {
                        dp[k+1][x1+1][x2+1] = ret + grid[x1+1][k-x1];
                        myqu.push(make_tuple(k+1, x1+1, x2+1, dp[k+1][x1+1][x2+1]));
                    }
                }
            }
            if(k-x1+1 < n && k-x2+1 < n && grid[x1][k-x1+1] != -1 && grid[x2][k-x2+1] != -1) {
                if(x1 != x2) {
                    if(ret + grid[x1][k-x1+1] + grid[x2][k-x2+1] > dp[k+1][x1][x2]) {
                        dp[k+1][x1][x2] = ret + grid[x1][k-x1+1] + grid[x2][k-x2+1];
                        myqu.push(make_tuple(k+1, x1, x2, dp[k+1][x1][x2]));
                    }
                }
                else {
                    if(ret + grid[x1][k-x1+1] > dp[k+1][x1][x2]) {
                        dp[k+1][x1][x2] = ret + grid[x1][k-x1+1];
                        myqu.push(make_tuple(k+1, x1, x2, dp[k+1][x1][x2]));
                    }
                }
            }
        }
        return dp[2*(n-1)][n-1][n-1]==-1?0:dp[2*(n-1)][n-1][n-1];
    }
};

// 动态规划+原地更新数组
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // 难的不谈
        // 可以把往返看作都是去
        // 要判断两个去是否经过了同一点（不能摘两次）
        // 所以让两次同时出发 这样方便判断是否经过了同一点
        // 用dp[k][x1][x2]表示，其中k是走的总路程 所以坐标分别是(x1, k-x1), (x2, k-x2)
        // 动态规划了 你妈妈的吻
        // 我们可以知道 所有动态规划用到的k-1的x1和x2要么和它相同 要么比它小 所以我们逆序遍历x1 x2 甚至不需要三维dp
        int n = grid.size();
        int dp[n+1][n+1];
        memset(dp, 0xff, sizeof(dp)); // 设成-1 这样在后面就不用判断了
        dp[0][0] = grid[0][0];
        for(int k = 1; k <= 2*(n-1); k++) {
            for(int x1 = min(k, n-1); x1 >= max(0, k-n+1); x1--) {
                int y1 = k - x1;
                for(int x2 = min(k, n-1); x2 >= x1; x2--) { // x2在x1的下方（默认，避免重复遍历）
                    int y2 = k - x2;
                    // 不能直接跳过 要把dp的值重制为-1 因为每次这里对应的是不同的k的结果
                    if(grid[x1][y1] == -1 || grid[x2][y2] == -1) {
                        dp[x1][x2] = -1;
                        continue;
                    }
                    // 有4种情况 分别带入
                    int res = dp[x1][x2]; // 都向右
                    if(x1) {
                        res = max(dp[x1-1][x2], res); // x1向下
                    }
                    if(x2) {
                        res = max(dp[x1][x2-1], res); // x2向下
                    }
                    if(x1&&x2) {
                        res = max(dp[x1-1][x2-1], res); // 都向下
                    }
                    if(res != -1) {
                        dp[x1][x2] = res + grid[x1][y1];
                        if(x1 != x2)
                            dp[x1][x2] += grid[x2][y2];
                    }
                }
            }
        }
        return max(0, dp[n-1][n-1]);
    }
};
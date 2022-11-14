class Solution {
public:
    // 广搜模版题
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].length();
        int x, y, status, step;
        int keyCnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    x = i;
                    y = j;
                }
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    keyCnt++;
                }
            }
        }
        bool dp[30][30][100] = {0}; // k 表示有无钥匙 0表示没有1表示有
        int dis[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<tuple<int, int, int, int>> myqu;
        myqu.push(make_tuple(x, y, 0, 0));
        dp[x][y][0] = true;
        while(!myqu.empty()) {
            auto tmp = myqu.front();
            myqu.pop();
            x = get<0>(tmp);
            y = get<1>(tmp);
            status = get<2>(tmp);
            step = get<3>(tmp);
            for(auto &d: dis) {
                int tmpx = x + d[0];
                int tmpy = y + d[1];
                if (tmpx < 0 || tmpx >= m || tmpy < 0 || tmpy >= n)
                    continue;
                if (grid[tmpx][tmpy] == '#') {
                    continue;
                }
                else if(grid[tmpx][tmpy] == '.' || grid[tmpx][tmpy] == '@') {
                    if (dp[tmpx][tmpy][status] == false) {
                        dp[tmpx][tmpy][status] = true;
                        myqu.push(make_tuple(tmpx, tmpy, status, step+1));
                    }
                    else {
                        continue;
                    }
                }
                else if(grid[tmpx][tmpy] >= 'A' && grid[tmpx][tmpy] <= 'Z') { // 锁
                    if((status >> (grid[tmpx][tmpy]-'A')) & 1) { // 有钥匙
                        if (dp[tmpx][tmpy][status] == false) {
                            dp[tmpx][tmpy][status] = true;
                            myqu.push(make_tuple(tmpx, tmpy, status, step+1));
                        }
                        else {
                            continue;
                        }
                    }
                    else {
                        continue;
                    }
                }
                else if(grid[tmpx][tmpy] >= 'a' && grid[tmpx][tmpy] <= 'z') { // 钥匙
                    int curStatus = status | (1 << (grid[tmpx][tmpy]-'a'));
                    if (curStatus == (int)pow(2, keyCnt)-1) { // 结束了
                        return step+1;
                    }
                    if (dp[tmpx][tmpy][curStatus] == false) {
                        dp[tmpx][tmpy][curStatus] = true;
                        myqu.push(make_tuple(tmpx, tmpy, curStatus, step+1));
                    }
                    else {
                        continue;
                    }
                }
            }

        }
        return -1;
    }
};
class Solution {
public:
    void DFS(vector<vector<int>>& grid, int x, int y, int idx, unordered_map<int, int>& cnt, int n) {
        cnt[idx]++;
        grid[x][y] = idx;
        int dis[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto& d: dis) {
            if(x + d[0] >= 0 && x + d[0] < n && y + d[1] >= 0 && y + d[1] < n && grid[x+d[0]][y+d[1]] == 1) {
                DFS(grid, x+d[0], y+d[1], idx, cnt, n);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> cnt;
        int idx = 2;
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    cnt[idx] = 0;
                    DFS(grid, i, j, idx, cnt, n);
                    res = max(res, cnt[idx]);
                    idx++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    int cur = 1;
                    int dis[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                    unordered_set<int> check;
                    for(auto& d: dis) {
                        if(i + d[0] >= 0 && i + d[0] < n && j + d[1] >= 0 && j + d[1] < n
                           && grid[i+d[0]][j+d[1]] != 0) {
                            check.insert(grid[i+d[0]][j+d[1]]);
                        }
                    }
                    for(auto i: check)
                        cur += cnt[i];
                    res = max(res, cur);
                }
            }
        }

        return res;
    }
};
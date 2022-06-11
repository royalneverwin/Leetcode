class Solution {
public:
    inline int numberToX(int number, int n){
        return number / n;
    }
    inline int numberToY(int number, int n){
        return number % n;
    }
    inline int XYToNumber(int x, int y, int n){
        return x * n + y;
    }

    vector<vector<int>> change = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // 广度优先搜索
    int DFS(vector<vector<int>>& forest, int sx, int sy, int tx, int ty){
        if(sx == tx && sy == ty)
            return 0;
        queue<tuple<int, int>> qu;
        int m = forest.size();
        int n = forest[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, 0));
        qu.emplace(XYToNumber(sx, sy, n), 0);
        visit[sx][sy] = 1;

        while(!qu.empty()){
            auto [number, dis] = qu.front();
            qu.pop();
            int cx = numberToX(number, n);
            int cy = numberToY(number, n);
            for(int i = 0; i < 4; i++){
                int nx = cx + change[i][0];
                int ny = cy + change[i][1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && forest[nx][ny] != 0 && !visit[nx][ny]){
                    if(nx == tx && ny == ty){
                        return dis + 1;
                    }

                    visit[nx][ny] = 1;
                    qu.emplace(XYToNumber(nx, ny, n), dis+1);
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, int>> points;
        int m = forest.size();
        int n = forest[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(forest[i][j] > 1)
                    points.emplace_back(make_pair(i, j));
            }
        }

        sort(points.begin(), points.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {return forest[a.first][a.second] < forest[b.first][b.second]; });
        int ans = 0;
        // 注意虽然起点可能有树，但也不能砍，要从最小的树开始砍
        int begin = 0;
        int end = 0;
        for(int i = 0; i < points.size(); i++){
            int dis = DFS(forest, begin, end, points[i].first, points[i].second);
            if(dis == -1)
                return -1;

            ans += dis;
            begin = points[i].first;
            end = points[i].second;
        }
        return ans;

    }
};
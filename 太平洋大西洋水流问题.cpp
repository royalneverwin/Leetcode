class Solution {
public:
    // 回溯比较好
    // 从边缘往中间过渡
    // 否则heights[i][j]相同的位置会互相重复迭代
    // 如果手动设置不重复的话可能会出现
    // xxx
    // xox
    // xxx
    // 匹配错误的情况
    // 当然 多匹配几次就可以避免
    // 但没必要
    void bfs(vector<vector<int>>& heights, vector<vector<short>>& result, int r, int c){
        int curResult = result[r][c];
        if(r == 0){
            curResult |= 1;
        }
        else if(heights[r-1][c] <= heights[r][c]){
            heights[r][c] += 1;
            // if(result[r-1][c] == -1)
            bfs(heights, result, r-1, c);
            heights[r][c] -= 1;
            curResult |= result[r-1][c];
        }

        if(curResult == 3){
            result[r][c] = curResult;
            return;
        }

        if(r == heights.size()-1)
            curResult |= 2;
        else if(heights[r+1][c] <= heights[r][c]){
            heights[r][c] += 1;
            // if(result[r+1][c] == -1)
            bfs(heights, result, r+1, c);
            heights[r][c] -= 1;
            curResult |= result[r+1][c];
        }


        if(curResult == 3){
            result[r][c] = curResult;
            return;
        }

        if(c == 0)
            curResult |= 1;
        else if(heights[r][c-1] <= heights[r][c]){
            heights[r][c] += 1;
            // if(result[r][c-1] == -1)
            bfs(heights, result, r, c-1);
            heights[r][c] -= 1;
            curResult |= result[r][c-1];
        }


        if(curResult == 3){
            result[r][c] = curResult;
            return;
        }

        if(c == heights[0].size()-1)
            curResult |= 2;
        else if(heights[r][c+1] <= heights[r][c]){
            heights[r][c] += 1;
            // if(result[r][c+1] == -1)
            bfs(heights, result, r, c+1);
            heights[r][c] -= 1;
            curResult |= result[r][c+1];
        }

        result[r][c] = curResult;

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> ans;
        vector<vector<short>> result(m, vector<short>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // if(result[i][j] == -1)
                bfs(heights, result, i, j);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << result[i][j] << ' ';
                if(result[i][j] == 3){
                    vector<int> tmp = {i, j};
                    ans.emplace_back(tmp);
                }
            }
            cout << endl;
        }

        return ans;
    }
};
class Solution {
public:
    bool ifVisited[50][50];
    void FillColor(vector<vector<int>> &grid, int row, int col, int color, int same){
        ifVisited[row][col] = true;
        bool Flag = false;
        if(row != 0){
            if(grid[row-1][col] == same && !ifVisited[row-1][col]){
                FillColor(grid, row-1, col, color, same);
            }
            else if(!ifVisited[row-1][col])
                Flag = true;
        }
        else
            Flag = true;
        if(row != grid.size() - 1){
            if(grid[row+1][col] == same && !ifVisited[row+1][col]){
                FillColor(grid, row+1, col, color, same);
            }
            else if(!ifVisited[row+1][col])
                Flag = true;
        }
        else
            Flag = true;
        if(col != 0){
            if(grid[row][col-1] == same && !ifVisited[row][col-1]){
                FillColor(grid, row, col-1, color, same);
            }
            else if(!ifVisited[row][col-1])
                Flag = true;
        }
        else
            Flag = true;
        if(col != grid[0].size() - 1){
            if(grid[row][col+1] == same && !ifVisited[row][col+1]){
                FillColor(grid, row, col+1, color, same);
            }
            else if(!ifVisited[row][col+1])
                Flag = true;
        }
        else
            Flag = true;
        if(Flag)
            grid[row][col] = color;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        memset(ifVisited, 0, sizeof(ifVisited));
        FillColor(grid, row, col, color, grid[row][col]);
        return grid;
    }
};
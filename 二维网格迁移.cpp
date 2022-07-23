class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans = vector<vector<int>>(m, vector<int>(n, 0)) ;
        int idx1 = k % (m*n);
        int idx2 = 0;

        while(idx2 < m*n) {
            ans[idx1 / n][idx1 % n] = grid[idx2 / n][idx2 % n];
            idx1 = (idx1 + 1) % (m*n);
            idx2++;
        }

        return ans;
    }
};
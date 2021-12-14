class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int HeightR[50];
        int HeightC[50];
        int length = grid.size();
        memset(HeightC, 0, sizeof(HeightC));
        memset(HeightR, 0, sizeof(HeightR));
        for(int i = 0; i < length; i++){
            for(int j = 0; j < length; j++){
                HeightR[i] = max(HeightR[i], grid[i][j]);
                HeightC[j] = max(HeightC[j], grid[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < length; i++){
            for(int j = 0; j < length; j++){
                ans += min(HeightC[j], HeightR[i]) - grid[i][j];
            }
        }
        return ans;
    }
};
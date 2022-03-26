class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<int> directx = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<int> directy = {-1, -1, -1, 0, 0, 1, 1, 1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sum = img[i][j];
                int cnt = 1;
                for(int k = 0; k < 8; k++){
                    int x = i + directx[k];
                    int y = j + directy[k];
                    if(x < 0 || x == m || y < 0 || y == n)
                        continue;
                    sum += img[x][y];
                    cnt++;
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};
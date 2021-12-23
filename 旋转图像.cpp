class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        int x1, y1, x2, y2, x3, y3, x4, y4;
        for(int i = 0; i < length / 2; i++){
            x1 = i;
            y1 = i;
            x2 = i;
            y2 = length - i - 1;
            x3 = length - i - 1;
            y3 = length - i - 1;
            x4 = length - i - 1;
            y4 = i;

            for(int j = 0; j < length - 1 - 2*i; j++){
                // 一次更新改四个位置
                int tmp = matrix[x1][y1 + j];
                matrix[x1][y1 + j] = matrix[x4 - j][y4];
                matrix[x4 - j][y4] = matrix[x3][y3 - j];
                matrix[x3][y3 - j] = matrix[x2 + j][y2];
                matrix[x2 + j][y2] = tmp;
            }
        }
    }
};
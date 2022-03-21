class Solution {
public:
    //  首先 肯定要两个数组存哪个行列要变0
    // 那就用矩阵中需要置0的某一行 这样就是原地算法
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flagRow = -1, flagCol = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!matrix[i][j]){
                    if(flagRow == -1){ // 找到标记数组
                        flagRow = i;
                        flagCol = j;
                    }
                    matrix[flagRow][j] = 0;
                    matrix[i][flagCol] = 0;
                }
            }
        }
        if(flagCol == -1 && flagRow == -1) // 没有0
            return;
        for(int j = 0; j < n; j++){
            if(!matrix[flagRow][j] && j != flagCol){ // 不要把flagCol给更新掉了
                for(int i = 0; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < m; i++){
            if(!matrix[i][flagCol]){ // 可以更新flagRow
                for(int j = 0; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < m; i++) // 最后更新flagCol
            matrix[i][flagCol] = 0;
    }
};
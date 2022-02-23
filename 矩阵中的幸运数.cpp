class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rowMin(m, 100000);
        // 找到每行的最小值
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rowMin[i] = min(rowMin[i], matrix[i][j]);
            }
        }
        // 找到每列的最大值
        vector<int> ans;
        for(int j = 0; j < n; j++){
            int maxNum = 0;
            int maxI;
            for(int i = 0; i < m; i++){
                if(matrix[i][j] > maxNum){
                    maxNum = matrix[i][j];
                    maxI = i;
                }
            }
            if(rowMin[maxI] == maxNum)
                ans.push_back(maxNum);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int direction = 0; // 0右, 1下, 2左, 3上
        int m = matrix.size();
        int n = matrix[0].size();
        int interval = 0; // 记录小矩阵的边界离大矩阵的边界的距离
        int x = 0, y = 0;
        vector<int> ans;
        ans.push_back(matrix[x][y]);
        while(1){
            if(direction == 0){
                if(y < n - interval - 1){
                    y++;
                }
                else if(x < m - interval - 1){
                    x++;
                    direction = 1;
                }
                else{
                    break;// 遍历完了, 可以结束了
                }
            }
            else if(direction == 1){
                if(x < m - interval - 1){
                    x++;
                }
                else if(y > interval){
                    y--;
                    direction = 2;
                }
                else{
                    break;// 遍历完了, 可以结束了
                }
            }
            else if(direction == 2){
                if(y > interval){
                    y--;
                }
                else if(x > interval + 1){ // 这里判断要注意, x的边界已经变为interval+1了
                    x--;
                    direction = 3;
                    interval++; // 在direction转到3时, interval++
                }
                else{
                    break;// 遍历完了, 可以结束了
                }
            }
            else{
                if(x > interval){
                    x--;
                }
                else if(y <  n - interval - 1){
                    y++;
                    direction = 0;
                }
                else{
                    break;// 遍历完了, 可以结束了
                }
            }
            ans.push_back(matrix[x][y]);
        }
        return ans;
    }
};
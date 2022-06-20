class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int x = 0, y = 0;
        vector<int> ans(m * n, 0);

        int index = 0;

        bool flag;
        if(y == n-1)
            flag = true;
        else if(x == m-1)
            flag = false;
        else
            flag = true;

        while(index < m * n) {
            ans[index] = mat[x][y];
            if(y == n-1) {
                if(flag == true) {// 刚到
                    x = x + 1;
                    if(y != 0)
                        flag = false;
                }
                else{ // 该走了
                    x = x + 1;
                    y = y - 1;
                }
            }
            else if(x == m-1) {
                if(flag == false) { // 刚到
                    y = y + 1;
                    if(x != 0)
                        flag = true;
                }
                else { // 该走了
                    x = x - 1;
                    y = y + 1;
                }
            }
            else if(x == 0) {
                if(flag == true) { // 刚到
                    y = y + 1;
                    flag = false;
                }
                else {
                    x = x + 1;
                    y = y - 1;
                }
            }
            else if(y == 0) {
                if(flag == false) { // 刚到
                    x = x + 1;
                    flag = true;
                }
                else { // 该走了
                    x = x - 1;
                    y = y + 1;
                }
            }
            else if(flag) {
                y = y + 1;
                x = x - 1;
            }
            else {
                y = y - 1;
                x = x + 1;
            }
            index++;
        }
        return ans;
    }
};

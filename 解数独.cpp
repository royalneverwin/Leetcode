//dfs
class Solution {
public:
    bool rowValid[9][10];
    bool colValid[9][10];
    bool recValid[9][10];
    void Preprocess(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                int k = 3 * (i / 3) + (j / 3); //which rec the value belongs to
                if(board[i][j] == '.')
                    continue;
                rowValid[i][board[i][j] - '0'] = true;
                colValid[j][board[i][j] - '0'] = true;
                recValid[k][board[i][j] - '0'] = true;
            }
        }
    }
    bool dfs(vector<vector<char>>& board, int x, int y){
        for(int i = x; i < 9; i++){
            for(int j = 0; j < 9; j++){ //注意这里不能从j = y开始！因为只是第i行从y开始，后面依然从0开始
                if(board[i][j] == '.'){
                    int k = 3 * (i / 3) + (j / 3);
                    for(int num = 1; num <= 9; num++){
                        if(!rowValid[i][num] && !colValid[j][num] && !recValid[k][num]){
                            // cout << i << ' ' << j << ' ' << num << endl;
                            board[i][j] = num + '0';
                            rowValid[i][num] = true;
                            colValid[j][num] = true;
                            recValid[k][num] = true;
                            int nexti, nextj;
                            if(j == 8){
                                nexti = i + 1;
                                nextj = 0;
                            }
                            else{
                                nexti = i;
                                nextj = j + 1;
                            }
                            if(dfs(board, nexti, nextj)){
                                return true;
                            }
                            //回溯
                            board[i][j] = '.';
                            rowValid[i][num] = false;
                            colValid[j][num] = false;
                            recValid[k][num] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(rowValid, 0, sizeof(rowValid));
        memset(colValid, 0, sizeof(colValid));
        memset(recValid, 0, sizeof(recValid));
        Preprocess(board);
        dfs(board, 0, 0);
    }
};
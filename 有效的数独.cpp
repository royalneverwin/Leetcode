class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowValid[9][9];
        bool colValid[9][9];
        bool recValid[9][9];
        memset(rowValid, 0, sizeof(rowValid));
        memset(colValid, 0, sizeof(colValid));
        memset(recValid, 0, sizeof(recValid));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                int k = 3 * (i / 3) + (j / 3); //which rec the value belongs to
                if(board[i][j] == '.')
                    continue;
                if(rowValid[i][board[i][j] - '1']){ // appear twice
                    // cout << 'i' << ' ' << i << ' ' << board[i][j] << endl;
                    return false;
                }
                else
                    rowValid[i][board[i][j] - '1'] = true;
                if(colValid[j][board[i][j] - '1']){ // appear twice
                    // cout << 'j' << ' ' << j << ' ' << board[i][j] << endl;
                    return false;
                }
                else
                    colValid[j][board[i][j] - '1'] = true;
                if(recValid[k][board[i][j] - '1']){ // appear twice
                    // cout << 'k' << ' ' << k << ' ' << board[i][j] << endl;
                    return false;
                }
                else
                    recValid[k][board[i][j] - '1'] = true;
            }
        }
        return true;
    }
};
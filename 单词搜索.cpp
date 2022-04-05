class Solution {
public:
    bool flag = false;
    void bfs(vector<vector<char>>& board, string& word, int index, int x, int y){
        if(index == word.size()){
            flag = true;
            return;
        }
        if(x != 0){
            if(board[x-1][y] == word[index]){
                board[x][y] = ' ';
                bfs(board, word, index+1, x-1, y);
                board[x][y] = word[index-1];
            }
        }
        if(x != board.size()-1){
            if(board[x+1][y] == word[index]){
                board[x][y] = ' ';
                bfs(board, word, index+1, x+1, y);
                board[x][y] = word[index-1];
            }
        }
        if(y != 0){
            if(board[x][y-1] == word[index]){
                board[x][y] = ' ';
                bfs(board, word, index+1, x, y-1);
                board[x][y] = word[index-1];
            }
        }
        if(y != board[0].size()-1){
            if(board[x][y+1] == word[index]){
                board[x][y] = ' ';
                bfs(board, word, index+1, x, y+1);
                board[x][y] = word[index-1];
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    board[i][j] = ' ';
                    bfs(board, word, 1, i, j);
                    board[i][j] = word[0];
                    if(flag)
                        return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int CntO = 0;
        int CntX = 0;
        bool ifXWin = false;
        bool ifOWin = false;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 'X')
                    CntX++;
                else if(board[i][j] == 'O')
                    CntO++;
            }
        }
        for(int i = 0; i < 3; i++){
            if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
                ifXWin = true;
            if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
                ifOWin = true;
        }
        for(int j = 0; j < 3; j++){
            if(board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X')
                ifXWin = true;
            if(board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O')
                ifOWin = true;
        }
        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
            ifXWin = true;
        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
            ifOWin = true;
        if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
            ifXWin = true;
        if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
            ifOWin = true;

        if(CntX - CntO != 0 && CntX - CntO != 1) // X if the first one
            return false;
        if(ifOWin && ifXWin) // all win if impossible
            return false;
        if(ifXWin && CntX == CntO) // X win condition
            return false;
        if(ifOWin && CntO != CntX) // O win condition
            return false;
        return true;
    }
};
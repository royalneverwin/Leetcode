class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int ans = 0;
        // 从左到右，从上到下遍历，遍历到x，如果它左边没有x，上边也没有x，那么这个x就是新的x
        // O（1）的空间复杂度，而且没有改变board
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    if(i == 0 && j == 0){
                        ans++;
                    }
                    else if(i == 0){
                        if(board[i][j-1] == '.')
                            ans++;
                    }
                    else if(j == 0){
                        if(board[i-1][j] == '.')
                            ans++;
                    }
                    else{
                        if(board[i-1][j] == '.' && board[i][j-1] == '.')
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};
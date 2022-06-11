class Solution {
public:
    unordered_map<int, bool>bp ; // 0 loss, 1 win
    bool canWinDFS(int maxChoosableInteger, int desiredTotal, int status, int curTotal){
        if(desiredTotal <= 0) // 出什么都是赢
            return 1;

        if(bp.count(status))
            return bp[status];

        for(int i = 1; i <= maxChoosableInteger; i++){
            if((status & (1 << (i-1))) == 0)
                continue;

            if(i + curTotal >= desiredTotal){ // 出了就赢
                bp[status] = 1;
                return true;
            }
            bool result = canWinDFS(maxChoosableInteger, desiredTotal, status ^ (1 << (i-1)), curTotal + i);
            if(result == 0){ // 对手稳输 就出这个
                bp[status] = 1;
                return 1;
            }
        }


        // 怎么都输
        bp[status] = 0;
        return 0;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int status = 0;
        if((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) // 平局
            return false;
        for(int i = 0; i < maxChoosableInteger; i++){
            status |= (1 << i);
        }
        return canWinDFS(maxChoosableInteger, desiredTotal, status, 0);
    }
};
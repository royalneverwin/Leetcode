class Solution {
public:
    //  很简单
    // 因为A和B的操作并不会影响对方 他们都删除中间的元素
    // 所以只要看A和B有几次操作就行
    bool winnerOfGame(string colors) {
        int cnt = 0;
        for(int i = 1; i < colors.length()-1; i++){
            if(colors[i-1] == 'A' && colors[i+1] == 'A' && colors[i] == 'A')
                cnt++;
            else if(colors[i-1] == 'B' && colors[i+1] == 'B' && colors[i] == 'B')
                cnt--;
        }
        return cnt > 0;
    }
};
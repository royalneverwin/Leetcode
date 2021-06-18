class Solution {
public:
    int reverse(int x) {
        bool ifminus = false;
        if(x < 0){
            if(x == (1 << 31)) //特殊处理
                return 0;
            ifminus = true;
            x = -x;
        }
        char int2s[50];
        int index = 0;
        while(x != 0){
            int2s[index] = x % 10 + '0';
            index++;
            x /= 10;
        }
        int2s[index] = 0;
        int ans = 0;
        for(int i = 0; i < index; i++){
            if(ans > (~(1 << 31)) / 10){ //超范围
                return 0;
            }
            ans *= 10;
            if(ans > (~(1 << 31)) - int2s[i] + '0'){ //超范围
                return 0;
            }
            ans += int2s[i] - '0';
        }
        if(ifminus)
            ans = -ans;
        return ans;
    }
};
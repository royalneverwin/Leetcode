class Solution {
public:
    int myAtoi(string s) {
        char num[210];
        int index = 0;
        int length = s.length();
        int step = 1;
        bool ifminus = 0;
        for(int i = 0; i < length; i++){
            if(step == 1){
                if(s[i] != ' '){
                    i -= 1;
                    step++;
                }
            }
            else if(step == 2){
                if(s[i] == '-'){
                    ifminus = 1;
                }
                else if(s[i] >= '0' && s[i] <= '9'){ //直接出数字，默认+
                    i -= 1;
                }
                else if(s[i] != '+'){ //非数字，返回0
                    return 0;
                }
                step++;
            }
            else if(step == 3){
                if(s[i] >= '0' && s[i] <= '9'){
                    num[index] = s[i];
                    index++;
                }
                else{
                    break;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < index; i++){
            if(ans > (~(1 << 31)) / 10){
                if(ifminus)
                    return 1 << 31;
                else
                    return (~(1 << 31));
            }
            ans *= 10;
            if(ans > (~(1 << 31)) - (num[i] - '0')){
                if(ifminus)
                    return 1 << 31;
                else
                    return (~(1 << 31));
            }
            ans += num[i] - '0';
        }
        if(ifminus)
            ans = -ans;
        return ans;
    }
};
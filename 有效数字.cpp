class Solution {
public:
    int haveSign(const string& s){
        if(s[0] == '+' || s[0] == '-')
            return 1;
        else if(s[0] >= '0' && s[0] <= '9')
            return 0;
        else if(s[0] == '.') // 错误
            return 2;
        else
            return -1;

    }
    bool isNumber(string s) {
        // 判断开头符号
        int cnt = haveSign(s);
        if(cnt > 0 && s.length() == 1)
            return false;
        else if(cnt > 0){
            s = s.substr(1, s.length()-1);
        }
        else if(cnt == -1)
            return false;


        int index = 0;
        while(s[index] >= '0' && s[index] <= '9' && index < s.length()){
            index++;
        }
        if(index == s.length()) // 全数字
            return true;
        else if(s[index] == '.' && cnt == 2) // 只有一个小数
            return false;
        else if(s[index] == '.'){ // 是小数
            if(index == 0 &&
               (s[index+1] == 'E' || s[index+1] == 'e' || s.length() == 1)){ // 至少要有数
                return false;
            }
            else if(index == s.length() - 1) // 最后一位是小数点
                return true;
            else{
                s = s.substr(index+1, s.length() - index - 1);
            }
            index = 0;
            while(s[index] >= '0' && s[index] <= '9' && index < s.length()){
                index++;
            }
            if(index == s.length()) // 全数字
                return true;
            else if(s[index] == 'E' || s[index] == 'e'){ // 有e
                if(index == s.length() - 1)
                    return false;
                else{
                    if(s[index+1] == '+' || s[index+1] == '-'){ // 把符号去掉
                        if(index+2 == s.length())
                            return false;
                        s = s.substr(index+2, s.length() - index - 2);
                    }
                    else
                        s = s.substr(index+1, s.length() - index - 1);
                }
                index = 0;
                while(index < s.length()){
                    if(s[index] < '0' || s[index] > '9')
                        return false;
                    index++;
                }
                return true;
            }
            else
                return false;
        }
        else if(s[index] == 'E' || s[index] == 'e'){ // 有e
            if(index == 0) // e不能在开头
                return false;
            else if(index == s.length() - 1) // e不能在结尾
                return false;
            else{
                if(s[index+1] == '+' || s[index+1] == '-'){ // 把符号去掉
                    if(index+2 == s.length())
                        return false;
                    s = s.substr(index+2, s.length() - index - 2);
                }
                else
                    s = s.substr(index+1, s.length() - index - 1);
            }
            index = 0;
            while(index < s.length()){
                if(s[index] < '0' || s[index] > '9')
                    return false;
                index++;
            }
            return true;
        }
        else{
            return false;
        }
    }
};
// 正则表达式匹配————动态规划

class Solution {
public:
    bool isMatch(string s, string p) {
        int indexS = 0;
        int indexP = 0;
        int lengthS = s.length();
        int lengthP = p.length();
        bool match[30][40]; //match[i][j]表示p前i个和s前j个能否匹配
        //我判断p前i个和s前j个，要看p[i-2]，因为有'*'存在(不用看p[i]因为我这里默认p只有长度i)
        memset(match, 0, sizeof(match));
        //p长度为0
        if(lengthS == 0 && lengthP == 0)
            return true;
        else if(lengthS != 0 && lengthP == 0)
            return false;
        match[0][0] = true;
        for(int j = 1; j <= lengthS; j++)
            match[0][j] = false;
        //p长度为1
        for(int j = 0; j <= lengthS; j++){
            if(j == 1){
                if(p[0] == s[0] || p[0] == '.')
                    match[1][1] = true;
                else
                    match[1][1] = false;
            }
            else{
                match[1][j] = false;
            }
        }
        //p长度从2到lengthP
        for(int i = 2; i <= lengthP; i++){
            for(int j = 0; j <= lengthS; j++){
                if(p[i-1] >= 'a' && p[i-1] <= 'z'){
                    if(j == 0)
                        match[i][j] = false;
                    else if(match[i-1][j-1] && p[i-1] == s[j-1])
                        match[i][j] = true;
                    else
                        match[i][j] = false;
                }
                else if(p[i-1] == '.'){
                    if(j == 0)
                        match[i][j] = false;
                    else if(match[i-1][j-1])
                        match[i][j] = true;
                    else
                        match[i][j] = false;
                }
                else{ //p[i-1] == '*'
                    if(match[i-2][j]) //先考虑需不需要让它把前一个去掉
                        match[i][j] = true;
                    else{ //再考虑使前一个个数>=1的情况
                        if(p[i-2] == '.'){
                            bool flag = false;
                            for(int k = 0; k <= j; k++){ //只要前面找到一个匹配，后面就肯定匹配
                                if(match[i-1][k]){
                                    match[i][j] = true;
                                    flag = true;
                                    break;
                                }
                            }
                            if(!flag){
                                match[i][j] = false;
                            }
                        }
                        else{ //p[i-2] == 'a' 到 'z'
                            bool flag1 = false;
                            for(int k = 0; k <= j; k++){
                                if(match[i-1][k]){ //找前面一个匹配
                                    bool flag2 = false;
                                    for(int l = k+1; l <= j; l++){ //看看从前一个匹配之后的s字符串是不是都等于p[i-2], 这样我们才能重复p[i-2]
                                        if(s[l-1] != p[i-2]){
                                            flag2 = true;
                                            break;
                                        }
                                    }
                                    if(!flag2){
                                        match[i][j] = true;
                                        flag1 = true;
                                        break;
                                    }
                                }
                            }
                            if(!flag1){
                                match[i][j] = false;
                            }
                        }
                    }
                }
            }
        }
        return match[lengthP][lengthS];
    }
};
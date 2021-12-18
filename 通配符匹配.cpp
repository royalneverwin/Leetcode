class Solution {
public:
    bool isMatch(string s, string p) {
        // 因为*可以匹配任何字符串, 不能单纯的遍历
        // 考虑DP
        int lengths = s.length();
        int lengthp = p.length();
        // 注意要考虑字符串长度为0的情况
        if(lengths == 0 && lengthp == 0){
            return true;
        }
        else if(lengths == 0){
            for(int i = 0; i < lengthp; i++){
                if(p[i] != '*')
                    return false;
            }
            return true;
        }
        else if(lengthp == 0){
            return false;
        }
        bool ismatch[lengths][lengthp]; // s到i， p到j开始是否能匹配
        memset(ismatch, 0, sizeof(ismatch));

        // preprocess
        if(s[0] == p[0] || p[0] == '?'){ // 只匹配第一个
            ismatch[0][0] = true;
            for(int i = 1; i < lengths; i++){
                ismatch[i][0] = false;
            }
        }
        else if(p[0] == '*'){ // 可匹配任意长s
            for(int i = 0; i < lengths; i++){
                ismatch[i][0] = true;
            }
        }
        else{ // 第一个都不匹配
            for(int i = 0; i < lengths; i++){
                ismatch[i][0] = false;
            }
        }
        bool flag = true;
        for(int j = 0; j < lengthp; j++){
            if(p[j] == '*') // '*'可以匹配空字符串
                ismatch[0][j] = true;
            else if(flag && (p[j] == s[0] || p[j] == '?')){ // 有一个不是'*', 但可匹配
                flag = false;
                ismatch[0][j] = true;
            }
            else{ // 后面都是false
                for(;j < lengthp; j++){
                    ismatch[0][j] = false;
                }
            }
        }

        // DP
        for(int i = 1; i < lengths; i++){
            for(int j = 1; j < lengthp; j++){
                if(p[j] == '*'){ // 只要s[0到i]与p[j-1]匹配，就一定和p[j]匹配
                    bool flag = false;
                    for(int k = 0; k <= i; k++){
                        if(ismatch[k][j-1]){
                            flag = true;
                            break;
                        }
                    }
                    ismatch[i][j] = flag;
                }
                else if(p[j] == '?'){ // obvious
                    if(ismatch[i-1][j-1])
                        ismatch[i][j] = true;
                    else
                        ismatch[i][j] = false;
                }
                else{ // obvious
                    if(p[j] == s[i] && ismatch[i-1][j-1])
                        ismatch[i][j] = true;
                    else
                        ismatch[i][j] = false;
                }
            }
        }
        return ismatch[lengths-1][lengthp-1];
    }
};
class Solution {
public:
    // 分治法
    // 注意一个更简单比较的方法：两个数记录大小写, 哪个小写或大写存在就让对应的位为1
    // 比较两个数是否相同 判断大小写是否都存在
    int maxPos, maxLen;

    void dfs(string& s, int start, int end){
        int mNum = 0, bNum = 0;
        if(end - start + 1 <= maxLen) // 已经找到更长的子串了
            return;

        for(int i = start; i <= end; i++){ // 判断是否是美好字符串
            if(s[i] >= 'a' && s[i] <= 'z')
                mNum |= (1 << (s[i] - 'a'));
            else
                bNum |= (1 << (s[i] - 'A'));
        }

        if(mNum == bNum){
            if(end - start + 1 > maxLen){ // 找到一个更长的美好字符串
                maxLen = end - start + 1;
                maxPos = start;
            }
        }

        else{ // 没找到更长的美好字符串, 以单个的字符为界限分割字符串
            int valid = mNum & bNum; // 有效字符（大小写都有）
            int pos = start;
            while(pos <= end){
                while(pos <= end && valid & (1 << (tolower(s[pos]) - 'a')))
                    pos++;
                dfs(s, start, pos - 1);
                start = pos + 1;
                pos = start;
            }
        }
    }

    string longestNiceSubstring(string s) {
        maxPos = maxLen = 0;
        dfs(s, 0, s.length() - 1);
        return s.substr(maxPos, maxLen);
    }
};


class Solution {
public:
    // 最复杂的方法, 更快的有分治、滑动窗口等
    bool isBeauty(string s){ // 判断是否是美好字符串
        bool flag[256];
        memset(flag, 0, sizeof(flag));
        for(int i = 0; i < s.length(); i++){
            flag[s[i]] = true;
        }
        for(char i = 'a'; i <= 'z'; i++){
            if(flag[i] == true && flag[i + 'A' - 'a'] == false)
                return false;
        }
        for(char i = 'A'; i <= 'Z'; i++){
            if(flag[i] == true && flag[i + 'a' - 'A'] == false)
                return false;
        }
        return true;
    }


    string longestNiceSubstring(string s) {
        int length = s.length();
        for(int j = length; j >= 2; j--){
            for(int i = 0; i <= length - j; i++){
                string tmp = s.substr(i, j);
                if(isBeauty(tmp))
                    return tmp;
            }
        }
        return "";
    }
};
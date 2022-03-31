class Solution {
public:
    bool Check(vector<int>& at, vector<int>& AT, vector<int>& as, vector<int>& AS){
        for(int i = 0; i < 26; i++){
            if(at[i] != 0 && at[i] > as[i])
                return false;
            if(AT[i] != 0 && AT[i] > AS[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";
        int ansLen = s.length()+1;
        int ansBegin;
        int left = 0, right = 0;
        vector<int> alphat(26, 0); // 存t小写
        vector<int> ALPHAT(26, 0); // 存t大写
        vector<int> alphas(26, 0); // 存s小写
        vector<int> ALPHAS(26, 0); // 存s大写
        // 创建alphat, ALPHAT
        // 初始化right
        for(int i = 0; i < t.length(); i++){
            if(t[i] >= 'A' && t[i] <= 'Z')
                ALPHAT[t[i] - 'A']++;
            else
                alphat[t[i] - 'a']++;
            if(s[i] >= 'A' && s[i] <= 'Z')
                ALPHAS[s[i] - 'A']++;
            else
                alphas[s[i] - 'a']++;
        }
        right = t.length();

        // 滑动窗口
        do{
            while(right < s.length()
                  && !Check(alphat, ALPHAT, alphas, ALPHAS)){ // 不匹配, right右移
                if(s[right] >= 'A' && s[right] <= 'Z')
                    ALPHAS[s[right] - 'A']++;
                else
                    alphas[s[right] - 'a']++;
                right++;
            }
            if(!Check(alphat, ALPHAT, alphas, ALPHAS)) // 找不到合适的了
                break;
            while(left < right
                  && Check(alphat, ALPHAT, alphas, ALPHAS)){ // left左移直到不能匹配
                if(s[left] >= 'A' && s[left] <= 'Z')
                    ALPHAS[s[left] - 'A']--;
                else
                    alphas[s[left] - 'a']--;
                left++;
            }
            if(ansLen > right - left + 1){ // 找最短的
                ansLen = right - left + 1;
                ansBegin = left - 1;
            }
        }while(right < s.length());
        if(ansLen == s.length() + 1)
            return "";
        else
            return s.substr(ansBegin, ansLen);
    }
};
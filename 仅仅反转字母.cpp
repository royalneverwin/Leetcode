class Solution {
public:
    bool isAlpha(char c){ // 判断是否是字母
        if(c >= 'a' && c <= 'z'){
            return true;
        }
        else if(c >= 'A' && c <= 'Z'){
            return true;
        }
        else{
            return false;
        }
    }

    string reverseOnlyLetters(string s) {
        int start = 0;
        int last = s.length()-1;
        while(start < s.length() && !isAlpha(s[start]))
            start++;
        while(last >= 0 && !isAlpha(s[last]))
            last--;

        while(start < last){
            // 翻转
            char tmp = s[start];
            s[start] = s[last];
            s[last] = tmp;

            start++;
            last--;
            while(start < s.length() && !isAlpha(s[start]))
                start++;
            while(last >= 0 && !isAlpha(s[last]))
                last--;
        }
        return s;
    }
};
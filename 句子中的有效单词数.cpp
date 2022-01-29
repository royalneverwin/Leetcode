class Solution {
public:
    bool isValid(string& sentence, int start, int end){ // 判断是否是有效单词
        int index = start;
        int cnt = 0;
        while(index < end){
            if(sentence[index] >= '0' && sentence[index] <= '9') // 有数字
                return false;
            else if(sentence[index] == '-'){ // 是连字符
                if(index == start || index == end - 1)
                    return false;
                else if(cnt == 1)
                    return false;
                else if(sentence[index - 1] < 'a' || sentence[index - 1] > 'z'
                        || sentence[index + 1] < 'a' || sentence[index + 1] > 'z')
                    return false;
                else
                    cnt++;
            }
            else if(sentence[index] >= 'a' && sentence[index] <= 'z'){ // 是小写字母
            }
            else{ // 是标点符号
                if(index != end - 1)
                    return false;
            }
            index++;
        }
        return true;
    }

    int countValidWords(string sentence) {
        int length = sentence.length();
        int ans = 0;
        int start = 0, end;
        while(sentence[start] == ' ') // 可能第一个字符是空格
            start++;
        end = start;
        while(1){
            while(end != length && sentence[end] != ' ') // 寻找token的end
                end++;
            if(isValid(sentence, start, end)) // 判断这个token是否是有效单词
                ans++;
            if(end == length) // 如果没有下一个token了
                return ans;
            // 寻找下一个token的start
            start = end;
            while(start != length && sentence[start] == ' ')
                start++;
            if(start == length) // 如果没有下一个token了
                return ans;
            else
                end = start;
        }
    }
};
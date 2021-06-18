class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256] = {0}; //存放char所在的index + 1
        int length = s.length();
        int maxLength = 0;
        int start = 0;
        for(int i = 0; i < length; i++){
            if(map[s[i]] == 0){
                map[s[i]] = i + 1;
            }
            else{
                int tmp = map[s[i]];
                for(int j = start; j < map[s[i]]; j++){
                    map[s[j]] = 0;
                }
                map[s[i]] = i + 1;
                start = tmp;
            }
            maxLength = max(maxLength, i - start + 1);
        }
        return maxLength;
    }
};
class Solution {
public:
    int cntAlpha[26];
    bool IfCover(string& word){
        int tmp[26];
        memset(tmp, 0, sizeof(tmp));
        for(int i = 0; i < word.length(); i++){
            tmp[word[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(cntAlpha[i] > tmp[i])
                return false;
        }
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        memset(cntAlpha, 0, sizeof(cntAlpha));
        for(int i = 0; i < licensePlate.length(); i++){
            if(licensePlate[i] >= 'a' && licensePlate[i] <= 'z'){
                cntAlpha[licensePlate[i] - 'a']++;
            }
            else if(licensePlate[i] >= 'A' && licensePlate[i] <= 'Z'){
                cntAlpha[licensePlate[i] - 'A']++;
            }
        }
        int ans = 0;
        int length = 16;
        for(int i = 0; i < words.size(); i++){
            if(IfCover(words[i]) && words[i].length() < length){
                ans = i;
                length = words[i].length();
            }
        }
        return words[ans];
    }
};
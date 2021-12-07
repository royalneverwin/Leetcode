class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        short alphaCnt[26];
        memset(alphaCnt, 0, sizeof(alphaCnt));
        for(int i = 0; i < magazine.length(); i++){
            alphaCnt[magazine[i] - 'a']++;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            alphaCnt[ransomNote[i]- 'a']--;
            if(alphaCnt[ransomNote[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};
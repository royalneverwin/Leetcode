class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i = 0; i < words.size(); i++) {
            unordered_map<char, char> f;
            bool flag[26] = {0};
            bool fflag = true;
            for(int j = 0; j < pattern.size(); j++) {
                if(!f.count(words[i][j])) {
                    if(flag[pattern[j] - 'a']) {
                        fflag = false;
                        break;
                    }
                    else {
                        flag[pattern[j] - 'a'] = true;
                        f[words[i][j]] = pattern[j];
                    }
                }
                else {
                    if(f[words[i][j]] != pattern[j]) {
                        fflag = false;
                        break;
                    }
                }
            }

            if(fflag)
                ans.emplace_back(words[i]);

        }

        return ans;
    }
};
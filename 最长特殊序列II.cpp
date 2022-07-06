class Solution {
public:
    bool isUnique(const string& s1, const string& s2) { // s1.l <= s2.l
        if(s1.length() == s2.length()) { // 相同的我已经在初始化的时候判false了 这里相同只是遇到了自己而已
            return true;
        }
        else { // s1.l < s2.l
            int index = 0;
            for(int i = 0; i < s2.length(); i++) {
                if(s2[i] == s1[index])
                    index++;

                if(index == s1.length())
                    break;
            }

            if(index == s1.length())
                return false;
            else
                return true;
        }
    }
    int findLUSlength(vector<string>& strs) {
        int maxLen = 0;
        int ans = -1;
        vector<vector<string>> strsList(10, vector<string>());
        unordered_map<string, bool> validStrs;
        for(int i = 0; i < strs.size(); i++) {
            strsList[strs[i].length()-1].emplace_back(strs[i]);

            if(!validStrs.count(strs[i]))
                validStrs[strs[i]] = true;
            else
                validStrs[strs[i]] = false;
        }

        for(auto& i: validStrs) {

            if(i.second) { // 判断是不是真的可以
                for(int j = i.first.length()-1; j < 10; j++) {
                    for(auto& k: strsList[j]) {
                        if(!isUnique(i.first, k)) {
                            i.second = false;
                            break;
                        }
                    }
                    if(!i.second)
                        break;
                }
            }
        }
        for(auto &i: validStrs) {
            if(i.second) {
                ans = max(ans, int(i.first.length()));
            }
        }
        return ans;
    }
};
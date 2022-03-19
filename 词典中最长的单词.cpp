class Solution {
public:
    static bool cmp(const string& s1, const string& s2){
        if(s1.length() < s2.length())
            return 1;
        else if(s1.length() > s2.length())
            return 0;
        else
            return s1 < s2;
    }

    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> check;
        int maxLen = 0;
        string ans = "";
        for(int i = 0; i < words.size(); i++){
            if(words[i].length() == 1){
                if(words[i].length() > maxLen){
                    maxLen = words[i].length();
                    ans = words[i];
                }
                check.insert(words[i]);
            }
            else{
                if(check.count(words[i].substr(0, words[i].length()-1))){
                    if(words[i].length() > maxLen){
                        maxLen = words[i].length();
                        ans = words[i];
                    }
                    check.insert(words[i]);
                }
            }
        }
        return ans;
    }
};
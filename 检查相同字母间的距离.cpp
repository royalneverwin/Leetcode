class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                for(int j = i+1; j < n; j++) {
                    if (s[j] == s[i]) {
                        if (distance[s[i]-'a'] != j-i-1) {
                            return false;
                        }
                        s[j] = ' ';
                        s[i] = ' ';
                        break;
                    }
                }
            }
        }
        return true;

    }
};
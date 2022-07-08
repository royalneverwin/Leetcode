class Solution {
public:
    static bool Cmp(const string& s1, const string& s2) {
        return s1.length() < s2.length();
    }

    string findPrefix(const string& s, vector<string>& dictionary) {
        for(auto& i: dictionary) {
            bool flag = true;
            for(int j = 0; j < i.length(); j++) {
                if(s[j] != i[j]) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                return i;
            }
        }

        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        sort(dictionary.begin(), dictionary.end(), Cmp);
        int idx1 = 0, idx2 = 0;
        while(idx2 < sentence.length()) {
            while(idx2 < sentence.length() && sentence[idx2] != ' ')
                idx2++;

            string tmp = sentence.substr(idx1, idx2 - idx1);
            ans += findPrefix(tmp, dictionary);
            if(idx2 != sentence.length()) {
                ans.append(1, ' ');
                idx1 = idx2 + 1;
                idx2 = idx1;
            }
        }

        return ans;
    }
};
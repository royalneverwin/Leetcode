class Solution {
public:
    unordered_map<string, int> hash; // 记忆华搜索

    int kSimilarity(string s1, string s2) {
        if(hash.count(s1+s2)) {
            return hash[s1+s2];
        }

        int idx1 = 0, idx2 = 0;
        int l = s1.length();
        int k = 100;
        while(idx1 < l) {
            if (s1[idx1] == s2[idx2])   {
                idx1++;
                idx2++;
            }
            else {
                int tmp = idx1+1;
                while(tmp < l) {
                    if(s1[tmp] == s2[idx2]) {
                        s1[tmp] = s1[idx1];
                        s1[idx1] = s2[idx2];
                        k = min(k, 1 + kSimilarity(s1.substr(idx1+1), s2.substr(idx2+1)));
                        // 回溯
                        s1[idx1] = s1[tmp];
                        s1[tmp] = s2[idx2];
                    }
                    tmp++;
                }
                hash[s1+s2] = k;
                return k;
            }
        }
        hash[s1+s2] = 0;
        return 0;
    }
};
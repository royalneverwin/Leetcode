class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int index1 = -1;
        int index2 = -1;
        int ans = 100010;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1) {
                if(index2 != -1)
                    ans = min(ans, i - index2);
                index1 = i;
            }
            else if(words[i] == word2) {
                if(index1 != -1)
                    ans = min(ans, i - index1);
                index2 = i;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> myHash;

        int ans = 0;

        for(int i = 0; i < words.size(); i++){
            string tmp;
            for(int j = 0; j < words[i].length(); j++){
                tmp += code[words[i][j] - 'a'];
            }
            if(!myHash.count(tmp)){
                ans++;
                myHash.insert(tmp);
            }
        }

        return ans;

    };
};
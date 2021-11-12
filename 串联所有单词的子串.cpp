//滑动窗口 + 剪枝 + map哈希
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> hashWords; //pay attention: maybe there are same words in vector words
        map<string, int> cntWords;
        vector<int> ans;
        int length = words[0].length();
        int total = words.size();
        if(s.length() < length * total) //特判
            return ans;
        for(auto &i: words){ //hash makes it faster to check
            if(hashWords.find(i) != hashWords.end()){
                hashWords[i]++;
                cntWords[i]++;
            }
            else{
                hashWords[i] = 1;
                cntWords[i] = 1;
            }
        }
        int cnt = 0;
        int index = 0;
        int begin;
        cout << s.length() << endl;
        cout << length * total << endl;
        cout << s.length() - length * total << endl;
        while(index <= s.length() - length * total){ //剪枝
            begin = index;
            while(begin < s.length()){
                string tmp = s.substr(begin, length);
                if(hashWords.find(tmp) != hashWords.end() && hashWords[tmp] != 0){
                    hashWords[tmp]--;
                    cnt++;
                    if(cnt == total){ //all words are in s.strStr
                        ans.push_back(index);
                        break;
                    }
                    begin += length;
                }
                else{
                    break;
                }
            }
            for(auto &i: words)
                hashWords[i] = cntWords[i];
            cnt = 0;
            index++;
        }
        return ans;
    }
};
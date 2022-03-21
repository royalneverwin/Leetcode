class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int beginIndex = 0;
        int index;
        int cnt;
        while(1){
            cnt = words[beginIndex].length();
            index = beginIndex + 1;
            vector<string> token = {words[beginIndex]};
            while(index < words.size()){ // 贪心放words
                if(cnt + words[index].length() + 1 <= maxWidth){
                    token.emplace_back(words[index]);
                    cnt += words[index].length() + 1;
                    index++;
                }
                else{
                    break;
                }
            }
            if(index == words.size()){ // 最后一列
                string perAns = token[0];
                for(int i = 1; i < token.size(); i++){
                    perAns.append(1, ' ');
                    perAns.append(token[i]);
                }
                perAns.append(maxWidth - cnt, ' ');
                ans.emplace_back(perAns);

                break;
            }
            else{ // 对称排列
                if(token.size() == 1){
                    string perAns = token[0];
                    perAns.append(maxWidth - cnt, ' ');
                    ans.emplace_back(perAns);

                }
                else{
                    int left = maxWidth - cnt;
                    int blank = left / (token.size() - 1) + 1;
                    left = left % (token.size() - 1);
                    string perAns = token[0];
                    for(int i = 1; i < token.size(); i++){
                        perAns.append(blank, ' ');
                        if(left > 0){
                            perAns.append(1, ' ');
                            left--;
                        }
                        perAns.append(token[i]);
                    }
                    ans.emplace_back(perAns);
                }
            }
            beginIndex = index;
        }
        return ans;
    }
};
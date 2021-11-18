class Solution {
public:
    //优化判断是否有公共字母部分：
    //给每个string一个标记, 如果有第i个字母就让第i位为1. 这样直接按位与就能知道是否有公共字母
    unsigned int mark[1000];
    void PreProcess(vector<string>& words){
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                mark[i] |= (1 << (words[i][j] - 'a'));
            }
        }
    }
    bool IfCover(int i, int j){
        if((mark[i] & mark[j]) == 0)
            return false;
        else
            return true;
    }

    int maxProduct(vector<string>& words) {
        memset(mark, 0, sizeof(mark));
        PreProcess(words);
        int ans = 0;
        for(int i = 0; i < words.size() - 1; i++){
            for(int j = i + 1; j < words.size(); j++){
                if(words[i].length() * words[j].length() <= ans)
                    continue;
                else if(IfCover(i, j)){
                    continue;
                }
                else{
                    ans = words[i].length() * words[j].length();
                }
            }
        }
        return ans;
    }
};
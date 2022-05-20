class Solution {
public:
    int DFS(vector<string> &stickers, const string &target, vector<int>& dp, int status){
        if(status == 0)
            return 0;

        if(dp[status] != 0)
            return dp[status];


        for(auto& sticker: stickers){
            short alpha[26] = {0};
            for(auto& c: sticker){
                alpha[c - 'a']++;
            }

            for(int i = 0; i < target.length(); i++){
                if(((status >> i) & 1) && alpha[target[i] - 'a']){ // 可以作为候选
                    int nextStatus = status;
                    for(int j = 0; j < target.length(); j++){
                        if(((status >> j) & 1) && alpha[target[j] - 'a']){ // 可以作为候选
                            nextStatus ^= (1 << j);
                            alpha[target[j] - 'a']--;
                        }
                    }

                    if(dp[status] == 0){ // return -1的话+1还是0
                        dp[status] = DFS(stickers, target, dp, nextStatus) + 1;
                    }
                    else{
                        dp[status] = min(dp[status], DFS(stickers, target, dp, nextStatus) + 1);
                    }


                    break;
                }
            }
        }

        if(dp[status] == 0){
            dp[status] = -1;
        }

        return dp[status];
    }


    int minStickers(vector<string>& stickers, string target) {
        // 动归
        // 状态压缩
        vector<int> dp((int)pow(2, 15), 0);
        int status = 0;
        for(int i = 0; i < target.length(); i++){
            status |= (1 << i);
        }

        return DFS(stickers, target, dp, status);
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        bool flag[n+1]; // 信任别人的人一定不是法官
        int cnt[n+1]; // 记录被信任的次数, 被信任n-1次且不信任别人就是法官
        memset(flag, 0, sizeof(flag));
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < trust.size(); i++){
            flag[trust[i][0]] = true;
            cnt[trust[i][1]]++;
        }
        bool flag2 = false;
        int ans = -1;
        for(int i = 1; i <= n; i++){
            if(flag[i] == 0 && cnt[i] == n-1){
                if(!flag2){
                    flag2 = true;
                    ans = i;
                }
                else // 不止一个人满足条件，不成立
                    return -1;
            }
        }
        return ans;
    }
};
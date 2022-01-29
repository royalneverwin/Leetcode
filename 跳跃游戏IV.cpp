class Solution {
public:
    typedef pair<int, int> pair;
    class Cmp{
    public:
        bool operator ()(const pair& a, const pair& b) const{
            return a.second > b.second;
        }
    };
    int minJumps(vector<int>& arr) {
        int length = arr.size();
        int dp[length];
        priority_queue<pair, vector<pair>, Cmp> qi; // 广搜
        map<int, vector<int>> mmap; // 有相同数值的数都存一块儿
        memset(dp, 0xff, sizeof(dp));

        // preprocess
        dp[length - 1] = 0;
        qi.push(make_pair(length - 1, 0));
        for(int i = 0; i < length - 1; i++){
            if(mmap.find(arr[i]) == mmap.end()){
                vector tmp = {i};
                mmap[arr[i]] = tmp;
            }
            else{
                mmap[arr[i]].push_back(i);
            }
            if(arr[i] == arr[length - 1]){
                dp[i] = 1;
                qi.push(make_pair(i, 1));
            }
        }

        // bfs
        while(!qi.empty()){
            pair tmp = qi.top();
            qi.pop();
            int index = tmp.first;
            int cnt = tmp.second;
            if(dp[index] != cnt){ // 处理下面同一个index的cnt+1和cnt+2都被push的情况
                continue;
            }
            if(index == 0)
                return cnt;
            else{
                if(dp[index - 1] == -1){ // 这种数没碰到过
                    int tmp = mmap[arr[index - 1]].size();
                    dp[index - 1] = cnt + 1;
                    qi.push(make_pair(index - 1, cnt + 1));
                    for(int i = 0; i < tmp; i++){
                        if(mmap[arr[index - 1]][i] != index - 1){
                            dp[mmap[arr[index - 1]][i]] = cnt + 2;
                            qi.push(make_pair(mmap[arr[index - 1]][i], cnt + 2));
                        }
                    }
                }
                else if(dp[index - 1] > cnt + 1){ // 在之前被设置成cnt + 2了
                    dp[index - 1] = cnt + 1;
                    qi.push(make_pair(index - 1, cnt + 1));
                }
            }
            if(index != length - 1){
                if(dp[index + 1] == -1){ // 这种数没碰到过
                    int tmp = mmap[arr[index + 1]].size();
                    dp[index + 1] = cnt + 1;
                    qi.push(make_pair(index + 1, cnt + 1));
                    for(int i = 0; i < tmp; i++){
                        if(mmap[arr[index + 1]][i] != index + 1){
                            dp[mmap[arr[index + 1]][i]] = cnt + 2;
                            qi.push(make_pair(mmap[arr[index + 1]][i], cnt + 2));
                        }
                    }
                }
                else if(dp[index + 1] > cnt + 1){ // 在之前被设置成cnt + 2了
                    dp[index + 1] = cnt + 1;
                    qi.push(make_pair(index + 1, cnt + 1));
                }
            }
        }
        return dp[0];
    }
};
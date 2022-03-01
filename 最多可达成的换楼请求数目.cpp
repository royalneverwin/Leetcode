class Solution {
public:
    int ans = 0;
    void dfs(int index, int length, int cnt, int n, vector<vector<int>>& requests,
             vector<int>& F){
        if(index == length){ // 遍历完了, 计算ans
            for(int i = 0; i < n; i++)
                if(F[i] != 0)
                    return;
            ans = max(ans, cnt);
        }
        else{
            if(cnt + length - index <= ans) // 剪枝1
                return;
            F[requests[index][0]]--;
            F[requests[index][1]]++;
            dfs(index+1, length, cnt+1, n, requests, F);
            F[requests[index][0]]++;
            F[requests[index][1]]--;
            if(cnt + length - index - 1 <= ans) // 剪枝2
                return;
            dfs(index+1, length, cnt, n, requests, F);
        }
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        // 不需要构造一个图！
        // 只需要看满足requests里面的组合后, 有没有满足每栋楼人数不变即可！
        // requests <= 16, 最多2^16种情况, 可以讨论, 而且很方便！
        // 不用去找什么最大环上点数目, 或者根据一个图来dfs, 太复杂了
        int length = requests.size();
        vector<int> F(n, 0);
        dfs(0, length, 0, n, requests, F);

        return ans;

    }
};
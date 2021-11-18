class Solution {
public:
    vector<vector<int>> ans;
    bool visited[100]; //剪枝3: 防止[1,1,1,1,1,1,1,1,...,1]的情况超时
    void bfs(vector<int>& candidates, int target, vector<int> tmpAns, int index, int left){
        if(target == 0){
            sort(tmpAns.begin(), tmpAns.end());
            if(find(ans.begin(), ans.end(), tmpAns) == ans.end())
                ans.push_back(tmpAns);
        }
        else if(index != candidates.size()){
            if(left - candidates[index] >= target) //剪枝1
                bfs(candidates, target, tmpAns, index + 1, left - candidates[index]);
            if(candidates[index] <= target){ //剪枝2
                if(index == 0 || visited[index - 1] || candidates[index - 1] != candidates[index]){
                    tmpAns.push_back(candidates[index]);
                    visited[index] = true;
                    bfs(candidates, target - candidates[index], tmpAns,
                        index + 1, left - candidates[index]);
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmpAns;
        memset(visited, 0, sizeof(visited));
        int sum = 0;
        for(int i = 0; i < candidates.size(); i++)
            sum += candidates[i];
        bfs(candidates, target, tmpAns, 0, sum);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
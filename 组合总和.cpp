#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
class Solution {
public:
    //bfs

    vector<vector<int>> ans;
    void bfs(vector<int>& candidates, int target, vector<int> tmpAns, int index){
        if(target == 0 && find(ans.begin(), ans.end(), tmpAns) == ans.end())
            ans.push_back(tmpAns);
        else if(index != candidates.size()){
            for(int j = 0; j <= target / candidates[index]; j++){
                vector<int> tmp = tmpAns;
                for(int k = 1; k <= j; k++){
                    tmp.push_back(candidates[index]);
                }
                bfs(candidates, target - j * candidates[index], tmp, index + 1);
            }
        }
    }
    // bool operator < (vector<int>& a, vector<int>& b){
    //     for(int i = 0; i < min(a.size(), b.size()); i++){
    //         if(a[i] == b[i])
    //             continue;
    //         else
    //             return a[i] < b[i];
    //     }
    //     if(i == a.size())
    //         return true;
    //     else
    //         return false;
    // }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //sort(candidates.begin(), candidates.end()); //排序
        vector<int> tmpAns;
        bfs(candidates, target, tmpAns, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
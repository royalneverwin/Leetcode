class Solution {
public:
    static bool cmp(const vector<int>& node1, const vector<int>& node2){
        return node1[0] != node2[0] ? node1[0] < node2[0] : node1[1] < node2[1];
    }

    int cross(const vector<int>& node1, const vector<int>& node2, const vector<int>& node3){
        int a1 = node2[0] - node1[0];
        int b1 = node2[1] - node1[1];
        int a2 = node3[0] - node2[0];
        int b2 = node3[1] - node2[1];
        return a1 * b2 - a2 * b1;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> ans;
        vector<int> ansIndex;
        vector<bool> flag(trees.size(), false);

        // 特殊处理
        if(trees.size() < 4)
            return trees;

        // 排序
        sort(trees.begin(), trees.end(), cmp);


        ansIndex.emplace_back(0); // 最后还要入栈 所以不标记
        ansIndex.emplace_back(1);
        flag[1] = true;

        // 先求下半壳
        int index = 2;
        while(index < trees.size()){
            if(cross(trees[ansIndex[ansIndex.size()-2]], trees[ansIndex[ansIndex.size()-1]], trees[index]) >= 0){ // 可以存进去
                ansIndex.emplace_back(index);
                flag[index] = true;
                index++;
            }
            else{ // 出栈
                flag[ansIndex[ansIndex.size()-1]] = false;
                ansIndex.pop_back();
                if(ansIndex.size() < 2){
                    ansIndex.emplace_back(index);
                    flag[index] = true;
                    index++;
                }
            }
        }

        // 再求上半壳
        int lowL = ansIndex.size();

        index = trees.size()-1;

        while(index >= 0 && flag[index])
            index--;

        // 先存一个顶点
        ansIndex.emplace_back(index);
        index--;

        while(index >= 0){
            if(flag[index]){
                index--;
            }
            else if(cross(trees[ansIndex[ansIndex.size()-2]], trees[ansIndex[ansIndex.size()-1]], trees[index]) >= 0) {
                ansIndex.emplace_back(index);
                flag[index] = true;
                index--;
            }
            else{
                flag[ansIndex[ansIndex.size()-1]] = false;
                ansIndex.pop_back();
                if(ansIndex.size() == lowL){
                    ansIndex.emplace_back(index);
                    flag[index] = true;
                    index--;
                }
            }
        }

        for(int i = 0; i < ansIndex.size()-1; i++)
            ans.emplace_back(trees[ansIndex[i]]);

        return ans;
    }
};
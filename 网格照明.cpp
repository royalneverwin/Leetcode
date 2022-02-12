class Solution {
public:
    void Renew(int n, unordered_map<int, unordered_set<int>>& on, unordered_map<int, int>& row, unordered_map<int, int>& col, unordered_map<int, int>& cross1, unordered_map<int, int>& cross2, int x, int y){
        // 更新on
        on[x].erase(y);
        // 更新row
        row[x]--;
        if(row[x] == 0)
            row.erase(x);
        // 更新col
        col[y]--;
        if(col[y] == 0)
            col.erase(y);
        // 更新cross1
        int forCross1 = x + y;
        cross1[forCross1]--;
        if(cross1[forCross1] == 0)
            cross1.erase(forCross1);
        // 更新cross2
        int forCross2 = x + (n-1-y);
        cross2[forCross2]--;
        if(cross2[forCross2] == 0)
            cross2.erase(forCross2);
    }

    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int length1 = lamps.size();
        int length2 = queries.size();
        vector<int> ans(length2, 0);

        // 基本思路：哈希表存行、列、两条对角线中被点亮的部分以及被点亮的次数
        // 另一个哈希表再存放点亮的灯lamps便于queries后关闭灯时更新存行列对角线的哈希表
        // 对queries中每个点看行、列、对角线是否在被点亮的部分, 如果在就1, 不在就0
        // 避免用pair, 不然要自己写hash, 会绝望的

        unordered_map<int, unordered_set<int>> on;
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        unordered_map<int, int> cross1;
        unordered_map<int, int> cross2;
        for(int i = 0; i < length1; i++){
            // 更新on
            if(on.find(lamps[i][0]) == on.end()){
                unordered_set<int> tmp;
                tmp.insert(lamps[i][1]);
                on[lamps[i][0]] = tmp;
            }
            else if(on[lamps[i][0]].find(lamps[i][1]) != on[lamps[i][0]].end()){
                // 已经点亮, 无需更新后续
                continue;
            }
            else{
                on[lamps[i][0]].insert(lamps[i][1]);
            }
            // 更新row
            if(row.find(lamps[i][0]) == row.end()){
                row[lamps[i][0]] = 1;
            }
            else{
                row[lamps[i][0]]++;
            }
            // 更新col
            if(col.find(lamps[i][1]) == col.end()){
                col[lamps[i][1]] = 1;
            }
            else{
                col[lamps[i][1]]++;
            }
            // 更新cross1
            int forCross1 = lamps[i][0] + lamps[i][1];
            if(cross1.find(forCross1) == cross1.end()){
                cross1[forCross1] = 1;
            }
            else{
                cross1[forCross1]++;
            }
            // 更新cross2
            int forCross2 = lamps[i][0] + (n - 1 - lamps[i][1]);
            if(cross2.find(forCross2) == cross2.end()){
                cross2[forCross2] = 1;
            }
            else{
                cross2[forCross2]++;
            }
        }

        for(int i = 0; i < length2; i++){
            // 判断
            int forCross1 = queries[i][0] + queries[i][1];
            int forCross2 = queries[i][0] + (n - 1 - queries[i][1]);
            if(row.find(queries[i][0]) != row.end()){
                ans[i] = 1;
            }
            else if(col.find(queries[i][1]) != col.end()){
                ans[i] = 1;
            }
            else if(cross1.find(forCross1) != cross1.end()){
                ans[i] = 1;
            }
            else if(cross2.find(forCross2) != cross2.end()){
                ans[i] = 1;
            }
            else{
                ans[i] = 0;
            }
            // 更新
            if(on.find(queries[i][0]-1) != on.end()){
                if(on[queries[i][0]-1].find(queries[i][1]-1) != on[queries[i][0]-1].end()){
                    Renew(n, on, row, col, cross1, cross2, queries[i][0]-1, queries[i][1]-1);
                }
                if(on[queries[i][0]-1].find(queries[i][1]) != on[queries[i][0]-1].end()){
                    Renew(n, on, row, col, cross1, cross2, queries[i][0]-1, queries[i][1]);
                }
                if(on[queries[i][0]-1].find(queries[i][1]+1) != on[queries[i][0]-1].end()){
                    Renew(n, on, row, col, cross1, cross2, queries[i][0]-1, queries[i][1]+1);
                }
            }
            if(on.find(queries[i][0]) != on.end()){
                if(on[queries[i][0]].find(queries[i][1]-1) != on[queries[i][0]].end()){
                    Renew(n, on, row, col, cross1, cross2, queries[i][0], queries[i][1]-1);
                }
                if(on[queries[i][0]].find(queries[i][1]) != on[queries[i][0]].end()){
                    Renew(n, on, row, col, cross1, cross2, queries[i][0], queries[i][1]);
                }
                if(on[queries[i][0]].find(queries[i][1]+1) != on[queries[i][0]].end()){
                    Renew(n, on, row, col, cross1, cross2, queries[i][0], queries[i][1]+1);
                }
            }
            if(on.find(queries[i][0]+1) != on.end()){
                if(on[queries[i][0]+1].find(queries[i][1]-1) != on[queries[i][0]+1].end()){
                    Renew(n, on, row, col, cross1, cross2, queries[i][0]+1, queries[i][1]-1);
                }
                if(on[queries[i][0]+1].find(queries[i][1]) != on[queries[i][0]+1].end()){
                    Renew(n, on, row, col, cross1, cross2, queries[i][0]+1, queries[i][1]);
                }
                if(on[queries[i][0]+1].find(queries[i][1]+1) != on[queries[i][0]+1].end()){
                    Renew(n, on, row, col, cross1, cross2, queries[i][0]+1, queries[i][1]+1);
                }
            }
        }
        return ans;
    }
};
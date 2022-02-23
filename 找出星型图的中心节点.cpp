class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> us;
        us.insert(edges[0][0]);
        us.insert(edges[0][1]);
        auto i = us.insert(edges[1][0]);
        if(!i.second)
            return edges[1][0];
        else
            return edges[1][1];
    }
};

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<bool> flag(100001, 0);
        flag[edges[0][0]] = 1;
        flag[edges[0][1]] = 1;
        if(flag[edges[1][0]])
            return edges[1][0];
        else
            return edges[1][1];
    }
};


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        else
            return edges[0][1];
    }
};
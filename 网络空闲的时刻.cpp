class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> dst(n, 0);
        vector<vector<int>> edgeList(n, vector<int>(0,0));
        for(int i = 0; i < edges.size(); i++){ // initate edgeList
            edgeList[edges[i][0]].emplace_back(edges[i][1]);
            edgeList[edges[i][1]].emplace_back(edges[i][0]);
        }
        queue<pair<int, int>> mq;
        mq.push(make_pair(0, 0));
        while(!mq.empty()){ // initate dst
            pair<int, int> tmp = mq.front();
            mq.pop();
            for(int i = 0; i < edgeList[tmp.first].size(); i++){
                if(edgeList[tmp.first][i] != 0 && dst[edgeList[tmp.first][i]] == 0){
                    dst[edgeList[tmp.first][i]] = tmp.second + 1;
                    mq.push(make_pair(edgeList[tmp.first][i], tmp.second + 1));
                }
            }
        }
        int ans = 0;
        for(int i = 1; i < n; i++){
            int time = dst[i] * 2;
            int left = time % patience[i];
            if(left == 0)
                time += time - patience[i];
            else if(left != patience[i])
                time += time - left;
            ans = max(ans, time);
        }
        return ans + 1;
    }
};
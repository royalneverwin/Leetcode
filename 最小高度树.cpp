class Solution {
public:
    // 返回最长链的最后一个节点
    int bfs(vector<vector<int>>& edgeList, vector<int>& parent, int begin, int n){
        vector<bool> flag(n, false);
        queue<int> myqu;
        myqu.push(begin);
        flag[begin] = true;
        parent[begin] = -1;
        int ret = 0;
        while(!myqu.empty()){
            int tmp = myqu.front();
            myqu.pop();
            ret = tmp;
            for(int i = 0; i < edgeList[tmp].size(); i++){
                if(!flag[edgeList[tmp][i]]){
                    myqu.push(edgeList[tmp][i]);
                    flag[edgeList[tmp][i]] = true;
                    parent[edgeList[tmp][i]] = tmp;
                }
            }
        }
        return ret;
    }


    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 选最长的边 找它的中点
        vector<int> tmp;
        vector<vector<int>> edgeList(n, tmp);
        for(int i = 0; i < edges.size(); i++){
            edgeList[edges[i][0]].push_back(edges[i][1]);
            edgeList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> parent(n, 0);
        vector<int> longLine;
        vector<int> ans;

        // 先从0开始找最远的index1
        // 在从那个最远的index1开始找最远的index2

        // 易知最长的链要么只有一条 要么中点相交
        // 所以只要求出一个最长的链 求它的中点就可以
        // parent记录父节点 便于在找到最长的链后向后推出整条链
        int oneStep = bfs(edgeList, parent, 0, n);
        int twoStep = bfs(edgeList, parent, oneStep, n);

        longLine.push_back(twoStep);
        while(parent[twoStep] != -1){
            twoStep = parent[twoStep];
            longLine.push_back(twoStep);
        }
        if(longLine.size() % 2 == 0)
            ans.push_back(longLine[longLine.size() / 2 - 1]);
        ans.push_back(longLine[longLine.size() / 2]);

        return ans;

    }
};
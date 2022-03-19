class Solution {
public:
    int dfs(vector<int>& treeCnt, vector<vector<int>>& children, int index){
        if(children[index][0] == -1) // 一个子节点没有
            treeCnt[index] = 1;
        else if(children[index][1] == -1) // 只有一个子节点
            treeCnt[index] = 1 + dfs(treeCnt, children, children[index][0]);
        else // 两个子节点
            treeCnt[index] = 1 + dfs(treeCnt, children, children[index][0]) +
                             dfs(treeCnt, children, children[index][1]);
        return treeCnt[index];
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> children(n, vector<int>(2, -1)); // 二叉树的i节点的孩子
        vector<int> treeCnt(n, -1); // 第i个节点为根的子树一共多少个节点
        for(int i = 1; i < n; i++){ // 构造children
            int father = parents[i];
            if(children[father][0] == -1)
                children[father][0] = i;
            else
                children[father][1] = i;
        }
        dfs(treeCnt, children, 0); // 构造treeCnt

        int ans = 0;
        long maxNum = -1;
        for(int i = 0; i < n; i++){
            long sum = 1; // 设大一点
            sum *= max(1, n - treeCnt[i]);
            if(children[i][1] != -1)
                sum *= treeCnt[children[i][1]];
            if(children[i][0] != -1)
                sum *= treeCnt[children[i][0]];
            if(sum > maxNum){
                maxNum = sum;
                ans = 1;
            }
            else if(sum == maxNum){
                ans++;
            }
        }

        return ans;
    }
};U
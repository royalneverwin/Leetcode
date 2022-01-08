class Solution {
public:
    int bp[50][50][100];
    int dfs(vector<vector<int>>& graph, int mouse, int cat, int turn){
        if(bp[mouse][cat][turn] != -1){
            return bp[mouse][cat][turn];
        }
        else if(turn % 2 == 0){ // 到老鼠走了
            int possible = 2;
            for(int i = 0; i < graph[mouse].size(); i++){
                int tmp = dfs(graph, graph[mouse][i], cat, turn+1);
                if(tmp == 0)
                    possible = 0;
                else if(tmp == 1){
                    possible = 1;
                    break;
                }
            }
            bp[mouse][cat][turn] = possible;
            return possible;
        }
        else{ // 到猫走了
            int possible = 1;
            for(int i = 0; i < graph[cat].size(); i++){
                if(graph[cat][i] == 0) // 猫不走0
                    continue;
                int tmp = dfs(graph, mouse, graph[cat][i], turn+1);
                if(tmp == 0)
                    possible = 0;
                else if(tmp == 2){
                    possible = 2;
                    break;
                }
            }
            bp[mouse][cat][turn] = possible;
            return possible;
        }
    }

    int catMouseGame(vector<vector<int>>& graph) {
        int mousePos = 1;
        int catPos = 2;
        int hole = 0;
        // 难点1: 用动态规划
        // 经典博弈论
        // bp[i][j][k]表示老鼠在i，猫在j，已经经历了k轮，结果
        // 因为都是最佳状态参与游戏，所以老鼠有必赢策略一定那么玩，猫有必赢策略也一样

        // 难点2: 知道最多判断多少回合就够了————2n回合
        // 为什么当 turns≥2n 时，游戏结果是平局呢？
        // 如果游戏已经进行了 2n 轮，但是仍然没有任何一方获胜，此时猫和老鼠各移动了 n 次。
        // 该移动次数等于图中的节点数，因此一定存在一个老鼠到达过至少两次的节点，以及一定存
        // 在一个猫到达过至少两次的节点。对于老鼠而言，即使按照最优策略，也无法躲入洞内，而是
        // 只能回到一个已经到达过的节点。当老鼠回到一个在过去的某个回合已经到达过的节点时，
        // 猫可能回到在相同回合已经到达过的节点，也可能移动到一个更有利于猫获胜的节点，不可能
        // 移动到一个更有利于老鼠获胜的节点（否则猫就不是按照最优策略参与游戏）。如果猫回到在
        // 相同回合已经到达过的节点，则形成循环，因此是平局；如果猫移动到一个更有利于猫获胜的
        // 节点，则老鼠的获胜机会更小，因此老鼠无法获胜。
        // 同理可知，如果猫按照最优策略也只能回到一个已经到达过的节点，则猫无法获胜。
        // 因此当猫和老鼠分别回到一个已经到达过的节点时，猫和老鼠都无法获胜，游戏结果是平局。

        // 难点3: 用dfs遍历, 根据遍历到的子节点的胜利可能性判断父节点的胜利可能性
        int length = graph.size();
        memset(bp, 0xFF, sizeof(bp));
        // preprocess
        for(int i = 0; i < length; i++){
            for(int j = 0; j < length * 2; j++){
                bp[0][i][j] = 1;
                bp[i][i][j] = 2;
                if(j < length && i != j && i != 0)
                    bp[i][j][2 * length - 1] = 0;
            }
        }
        // 注意, turn是偶数则是老鼠走, turn是奇数则是猫走
        return dfs(graph, 1, 2, 0);
    }
};
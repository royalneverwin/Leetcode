class Solution {
public:
    struct Point{
        int mrow;
        int mcol;
        int crow;
        int ccol;
        bool turn; // 0表示mouse 1表示cat
        Point(int mr, int mc, int cr, int cc, bool tt){
            mrow = mr;
            mcol = mc;
            crow = cr;
            ccol = cc;
            turn = tt;
        }
    };
    vector<vector<int>> dirs = {{-1,0}, {0,1},{1,0},{0,-1}};

    vector<Point> FindPreState(const Point& tmp, vector<string>& grid, int catJump, int mouseJump){
        // cout << "begin: " << endl;
        // cout << tmp.mrow << ' ' << tmp.mcol << ' ' << tmp.crow << ' ' << tmp.ccol << ' ' << tmp.turn << endl;   
        bool turn = tmp.turn ? 0 : 1;
        int curRow = turn ? tmp.crow : tmp.mrow;
        int curCol = turn ? tmp.ccol : tmp.mcol;
        int maxJump = turn ? catJump : mouseJump;
        int rows = grid.size();
        int cols = grid[0].length();
        vector<Point> ret;

        ret.emplace_back(Point(tmp.mrow, tmp.mcol, tmp.crow, tmp.ccol, turn)); // 可能原地不动！
        for(auto& dir: dirs){
            for(int i = curRow + dir[0], j = curCol + dir[1], cnt = 1;
                i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] != '#' && cnt <= maxJump;
                i += dir[0], j += dir[1], cnt++){
                int prevmrow = turn ? tmp.mrow : i;
                int prevmcol = turn ? tmp.mcol : j;
                int prevcrow = turn ? i : tmp.crow;
                int prevccol = turn ? j : tmp.ccol;

                ret.emplace_back(Point(prevmrow, prevmcol, prevcrow, prevccol, turn));
            }
        }
        // cout << "end" << endl;

        return ret;
    }

    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        // 动归 但轮数太多了（1000轮
        // 所以改成 拓扑排序 先算每一个点的度 根据度来反向计算
        int rows = grid.size();
        int cols = grid[0].length();
        // 先mouse后cat 0下一步老鼠走 1下一步猫走
        int result[rows][cols][rows][cols][2]; // 0不知道 1老鼠胜 2猫胜
        int move[rows][cols][rows][cols][2]; // 记录move次数
        int degree[rows][cols][rows][cols][2]; // 节点的度
        int Frow = 0, Fcol = 0;
        int Crow = 0, Ccol = 0;
        int Mrow = 0, Mcol = 0;
        queue<Point> myqu;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 'F'){
                    Frow = i;
                    Fcol = j;
                }
                if(grid[i][j] == 'C'){
                    Crow = i;
                    Ccol = j;
                }
                if(grid[i][j] == 'M'){
                    Mrow = i;
                    Mcol = j;
                }
            }
        }
        memset(result, 0, sizeof(result));
        memset(move, 0, sizeof(move));
        memset(degree, 0, sizeof(degree));

        // 算degree
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '#')
                    continue;
                for(int k = 0; k < rows; k++){
                    for(int l = 0; l < cols; l++){
                        if(grid[k][l] == '#')
                            continue;
                        degree[i][j][k][l][0]++; // 可能原地不动！
                        degree[i][j][k][l][1]++; // 可能原地不动！
                        for(auto &dir: dirs){
                            for(int curRow = i + dir[0], curCol = j + dir[1], cnt = 1;
                                curRow >= 0 && curRow < rows && curCol >= 0 && curCol < cols && grid[curRow][curCol] != '#' && cnt <= mouseJump;
                                curRow += dir[0], curCol += dir[1], cnt++){
                                degree[curRow][curCol][k][l][0]++; // 这个点可以到我这个点 故度数++
                            }
                        }
                        for(auto &dir: dirs){
                            for(int curRow = k + dir[0], curCol = l + dir[1], cnt = 1;
                                curRow >= 0 && curRow < rows && curCol >= 0 && curCol < cols && grid[curRow][curCol] != '#' && cnt <= catJump;
                                curRow += dir[0], curCol += dir[1], cnt++){
                                degree[i][j][curRow][curCol][1]++; // 这个点可以到我这个点 故度数++
                            }
                        }
                    }
                }
            }
        }

        // 如果猫跟老鼠处在相同的位置，那么猫获胜。
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != '#'){
                    result[i][j][i][j][0] = 2;
                    result[i][j][i][j][1] = 2;
                    move[i][j][i][j][0] = 0;
                    move[i][j][i][j][1] = 0;
                    myqu.push(Point(i, j, i, j, 0));
                    myqu.push(Point(i, j, i, j, 1));
                }
            }
        }

        // 如果猫先到达食物，那么猫获胜。
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != '#' && grid[i][j] != 'F'){ // 猫和鼠相同位置前面已经算过了 不用重复算
                    result[i][j][Frow][Fcol][0] = 2;
                    result[i][j][Frow][Fcol][1] = 2;
                    move[i][j][Frow][Fcol][0] = 0;
                    move[i][j][Frow][Fcol][1] = 0;
                    myqu.push(Point(i, j, Frow, Fcol, 0));
                    myqu.push(Point(i, j, Frow, Fcol, 1));
                }
            }
        }

        // 如果老鼠先到达食物且猫没有到达食物，那么老鼠获胜。
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != 'F' && grid[i][j] != '#'){
                    result[Frow][Fcol][i][j][0] = 1;
                    result[Frow][Fcol][i][j][1] = 1;
                    move[Frow][Fcol][i][j][0] = 0;
                    move[Frow][Fcol][i][j][1] = 0;
                    myqu.push(Point(Frow, Fcol, i, j, 0));
                    myqu.push(Point(Frow, Fcol, i, j, 1));
                }
            }
        }


        // 拓扑排序
        while(!myqu.empty()){
            Point tmp = myqu.front();
            myqu.pop();

            int curResult = result[tmp.mrow][tmp.mcol][tmp.crow][tmp.ccol][tmp.turn];
            int curMove = move[tmp.mrow][tmp.mcol][tmp.crow][tmp.ccol][tmp.turn];

            vector<Point> preState = FindPreState(tmp, grid, catJump, mouseJump);

            for(auto& p: preState){
                if(result[p.mrow][p.mcol][p.crow][p.ccol][p.turn] == 0){
                    bool win = ((p.turn == 0) && (curResult == 1)) || ((p.turn == 1) && (curResult == 2));
                    if(win){
                        result[p.mrow][p.mcol][p.crow][p.ccol][p.turn] = curResult;
                        move[p.mrow][p.mcol][p.crow][p.ccol][p.turn] = curMove + 1;
                        myqu.push(Point(p.mrow, p.mcol, p.crow, p.ccol, p.turn));
                    }
                    else{
                        degree[p.mrow][p.mcol][p.crow][p.ccol][p.turn]--;
                        if(p.mrow == Frow-1 && p.mcol == Fcol && p.crow == Crow && p.ccol == Ccol)
                            cout << "AAAA" << endl;
                        if(degree[p.mrow][p.mcol][p.crow][p.ccol][p.turn] == 0){
                            result[p.mrow][p.mcol][p.crow][p.ccol][p.turn] = p.turn ? 1 : 2;
                            move[p.mrow][p.mcol][p.crow][p.ccol][p.turn] = curMove + 1;
                            myqu.push(Point(p.mrow, p.mcol, p.crow, p.ccol, p.turn));
                        }
                    }
                }
            }
        }

        return (result[Mrow][Mcol][Crow][Ccol][0] == 1) && (move[Mrow][Mcol][Crow][Ccol][0] <= 1000);
    }
};
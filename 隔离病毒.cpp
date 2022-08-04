class Solution {
public:
    // 深搜寻找下一步感染方块的个数
    void DFS(int idx, vector<vector<int>>& isInfected, vector<vector<pair<int, int>>>& blockPoint,
    int &cnt1, int &cnt2, int x, int y, int m, int n) {
        isInfected[x][y] = 2;
        blockPoint[idx].emplace_back(make_pair(x, y));
        if(x) {
            if(isInfected[x-1][y]!=-idx && isInfected[x-1][y]!=1 &&
               isInfected[x-1][y]!=2 && isInfected[x-1][y]!=3) {
                isInfected[x-1][y] = -idx;
                cnt1++;
                cnt2++;
            }
            else if(isInfected[x-1][y] == -idx) {
                cnt1++;
            }
            else if(isInfected[x-1][y] == 1) {
                DFS(idx, isInfected, blockPoint, cnt1, cnt2, x-1, y, m, n);
            }

        }
        if(x != m-1) {
            if(isInfected[x+1][y]!=-idx && isInfected[x+1][y]!=1 &&
               isInfected[x+1][y]!=3 && isInfected[x+1][y]!=2) {
                isInfected[x+1][y] = -idx;
                cnt1++;
                cnt2++;
            }
            else if(isInfected[x+1][y] == -idx) {
                cnt1++;
            }
            else if(isInfected[x+1][y] == 1) {
                DFS(idx, isInfected, blockPoint, cnt1, cnt2, x+1, y, m, n);
            }
        }
        if(y) {
            if(isInfected[x][y-1]!=-idx && isInfected[x][y-1]!=1 &&
               isInfected[x][y-1]!=3 && isInfected[x][y-1]!=2) {
                isInfected[x][y-1] = -idx;
                cnt1++;
                cnt2++;
            }
            else if(isInfected[x][y-1] == -idx) {
                cnt1++;
            }
            else if(isInfected[x][y-1] == 1) {
                DFS(idx, isInfected, blockPoint, cnt1, cnt2, x, y-1, m, n);
            }
        }
        if(y != n-1) {
            if(isInfected[x][y+1]!=-idx && isInfected[x][y+1]!=1 &&
               isInfected[x][y+1]!=3 && isInfected[x][y+1]!=2) {
                isInfected[x][y+1] = -idx;
                cnt1++;
                cnt2++;
            }
            else if(isInfected[x][y+1] == -idx) {
                cnt1++;
            }
            else if(isInfected[x][y+1] == 1) {
                DFS(idx, isInfected, blockPoint, cnt1, cnt2, x, y+1, m, n);
            }
        }
    }
    int containVirus(vector<vector<int>>& isInfected) {
        // 0: 未感染; 1: 感染; 2: DFS已算过的感染; -idx: DFS已算过的将被感染; 3: 被隔离的已感染
        int ans = 0;
        // 看下一步每个block感染方块的个数 并找到会感染最多的block
        int m = isInfected.size();
        int n = isInfected[0].size();
        while(true) {
            vector<vector<pair<int, int>>> blockPoint;
            blockPoint.emplace_back(vector<pair<int, int>>());
            int maxCnt1 = -1;
            int maxCnt2 = -1;
            int maxIdx = 1;
            bool flag = false;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(isInfected[i][j] == 1) {
                        flag = true;
                        int cnt1 = 0; // 隔离板数量
                        int cnt2 = 0; // 下一步被感染的方块数量
                        blockPoint.emplace_back(vector<pair<int, int>>());
                        int idx = blockPoint.size()-1;
                        DFS(idx, isInfected, blockPoint, cnt1, cnt2, i, j, m, n);
                        if(maxCnt2 < cnt2) {
                            maxCnt2 = cnt2;
                            maxCnt1 = cnt1;
                            maxIdx = idx;
                        }
                    }
                }
            }
            if(!flag) {
                return ans;
            }
            // 对可以感染最多的block进行封锁 并更新ans
            ans += maxCnt1;
            for(auto &p: blockPoint[maxIdx]) {
                isInfected[p.first][p.second] = 3;
            }
            // 更新isInfected
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(isInfected[i][j] == 2) {
                        isInfected[i][j] = 1;
                        if(i!=0 && isInfected[i-1][j]!=1 && isInfected[i-1][j]!=2 && isInfected[i-1][j]!=3) {
                            isInfected[i-1][j] = 1;
                        }
                        if(i!=m-1 && isInfected[i+1][j]!=1 && isInfected[i+1][j]!=2 && isInfected[i+1][j]!=3) {
                            isInfected[i+1][j] = 1;
                        }
                        if(j!=0 && isInfected[i][j-1]!=1 && isInfected[i][j-1]!=2 && isInfected[i][j-1]!=3) {
                            isInfected[i][j-1] = 1;
                        }
                        if(j!=n-1 && isInfected[i][j+1]!=1 && isInfected[i][j+1]!=2 && isInfected[i][j+1]!=3) {
                            isInfected[i][j+1] = 1;
                        }
                    }
                    else if(isInfected[i][j] < 0) {
                        isInfected[i][j] = 0;
                    }
                }
            }
        }
    }
};
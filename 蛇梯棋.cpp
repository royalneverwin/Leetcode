class Solution {
public:
    typedef pair<int, int> pair;
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();


        // 构造number对应的x, y
        unordered_map<int, pair> umap;
        int x = n-1, y = 0;
        int cur = 1;
        bool direct = true; // true是向右，false向左
        while(x >= 0){
            umap[cur] = make_pair(x, y);
            cur++;
            if(direct){
                if(y != n-1)
                    y++;
                else{
                    direct = false;
                    x--;
                }
            }
            else{
                if(y != 0)
                    y--;
                else{
                    direct = true;
                    x--;
                }
            }
        }

        // 广搜
        queue<pair> myqu; // first是值 second是移动次数
        vector<bool> flag(n*n, false);
        int ans = 0;
        myqu.push(make_pair(1, 0));
        flag[0] = true;
        while(!myqu.empty()){
            pair tmp = myqu.front();
            myqu.pop();
            if(tmp.first == n*n){
                return tmp.second;
            }
            int nextX, nextY;
            for(int i = tmp.first+1; i <= min(tmp.first+6, n*n); i++){
                nextX = umap[i].first;
                nextY = umap[i].second;

                if(board[nextX][nextY] != -1){
                    if(flag[board[nextX][nextY]-1]== false){
                        int nextNumber = board[nextX][nextY];
                        myqu.push(make_pair(nextNumber, tmp.second+1));
                        flag[board[nextX][nextY]-1] = true;
                    }
                }
                else if(flag[i-1] == false){
                    flag[i-1] = true;
                    myqu.push(make_pair(i, tmp.second+1));
                }
            }
        }

        return -1;
    }
};
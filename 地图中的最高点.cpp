class Solution {
public:
    struct point{
        int x;
        int y;
        int h;
        point(int xx, int yy, int hh): x(xx), y(yy), h(hh){}
    };

    void Insert(vector<vector<int>>& ans, queue<point>& myqu, int x, int y, int h){
        if(ans[x][y] == -1){
            ans[x][y] = h;
            myqu.push(point(x, y, h));
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<point> myqu;
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    myqu.push(point(i, j, 0));
                }
            }
        }
        while(!myqu.empty()){
            point tmp = myqu.front();
            myqu.pop();
            int x = tmp.x;
            int y = tmp.y;
            int h = tmp.h;
            if(x != 0){
                Insert(ans, myqu, x-1, y, h+1);
            }
            if(x != m - 1){
                Insert(ans, myqu, x+1, y, h+1);
            }
            if(y != 0){
                Insert(ans, myqu, x, y-1, h+1);
            }
            if(y != n-1){
                Insert(ans, myqu, x, y+1, h+1);
            }
        }
        return ans;
    }
};
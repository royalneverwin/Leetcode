class Solution {
public:
    // 经典回溯题
    // 也可以用位运算, 把string换成int（因为不需要求解所有解了， 所以会方便许多）
    bool ifRight(vector<pair<int, int>>& Qpoint, int k, int col){
        for(int i = 0; i < Qpoint.size(); i++){
            if(Qpoint[i].second == col)
                return false;
            if(abs(Qpoint[i].first - k) == abs(Qpoint[i].second - col))
                return false;
        }
        return true;
    }
    void traceback(int& ans, vector<string>& cur,
                   vector<pair<int, int>>& Qpoint, int n, int k){ // n皇后，第k个
        if(k == n){
            ans++;
        }
        else{ // 第k行
            for(int col = 0; col < n; col++){
                if(ifRight(Qpoint, k, col)){
                    Qpoint.push_back(make_pair(k, col));
                    cur[k][col] = 'Q';
                    traceback(ans, cur, Qpoint, n, k+1);
                    // 回溯
                    cur[k][col] = '.';
                    Qpoint.erase(find(Qpoint.begin(), Qpoint.end(), make_pair(k, col)));
                }
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        string tmp(n, '.');
        vector<string> cur(n, tmp);
        vector<pair<int, int>> Qpoint;
        traceback(ans, cur, Qpoint, n, 0);
        return ans;
    }
};
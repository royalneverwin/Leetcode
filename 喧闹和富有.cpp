class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> richerList;
        int length = quiet.size();
        for(int i = 0; i < length; i++){
            vector<int> tmp;
            richerList.push_back(tmp);
        }
        for(int i = 0; i < richer.size(); i++){
            richerList[richer[i][1]].push_back(richer[i][0]);
        }
        queue<int> qi;
        bool ifVisited[500];
        vector<int> ans;
        int minQuiet;
        int minIndex;
        for(int i = 0; i < length; i++){
            memset(ifVisited, 0, sizeof(ifVisited));
            minIndex = i;
            minQuiet = quiet[i];
            qi.push(i);
            ifVisited[i] = true;
            while(!qi.empty()){
                int tmp = qi.front();
                qi.pop();
                for(int j = 0; j < richerList[tmp].size(); j++){ // add richer one into it
                    if(!ifVisited[richerList[tmp][j]]){
                        qi.push(richerList[tmp][j]);
                        ifVisited[richerList[tmp][j]] = true;
                    }
                }
                if(quiet[tmp] < minQuiet){
                    minQuiet = quiet[tmp];
                    minIndex = tmp;
                }
            }
            ans.push_back(minIndex);
        }
        return ans;
    }
};

// 优化, 我们可以先算richer的ans, 这样可以直接比较richer的ans的quiet值来计算比他poor的人的ans
class Solution {
public:
    vector<vector<int>> richerList;
    void dp(vector<int>& quiet, vector<int>& ans, int index){
        int minQ = quiet[index];
        int minI = index;
        for(int i = 0; i < richerList[index].size(); i++){
            int tmp = richerList[index][i];
            if(ans[tmp] == -1) // first calculate richer one's ans
                dp(quiet, ans, tmp);
            if(minQ > quiet[ans[tmp]]){ // ans[tmp] is richer one's quietest
                minQ = quiet[ans[tmp]];
                minI = ans[tmp];
            }
        }
        ans[index] = minI;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int length = quiet.size();
        for(int i = 0; i < length; i++){
            vector<int> tmp;
            richerList.push_back(tmp);
        }
        for(int i = 0; i < richer.size(); i++){
            richerList[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int> ans(length, -1);
        for(int i = 0; i < length; i++){
            if(ans[i] == -1)
                dp(quiet, ans, i);
        }
        return ans;
    }
};
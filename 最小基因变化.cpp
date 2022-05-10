class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string, int>> myqu;
        vector<bool> flag(bank.size(), 0);
        myqu.push(make_pair(start, 0));
        while(!myqu.empty()){
            pair<string, int> tmp = myqu.front();
            myqu.pop();
            for(int i = 0; i < bank.size(); i++){
                if(flag[i])
                    continue;
                int cnt = 0;
                for(int j = 0; j < 8; j++){
                    if(tmp.first[j] != bank[i][j])
                        cnt++;
                }

                if(cnt == 1){
                    if(bank[i] == end)
                        return tmp.second + 1;
                    myqu.push(make_pair(bank[i], tmp.second+1));
                    flag[i] = 1;
                }

            }
        }

        return -1;
    }
};
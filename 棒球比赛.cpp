class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        int ans = 0;
        int cnt;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "+"){
                cnt = score[score.size()-1] + score[score.size()-2];
                score.emplace_back(cnt);
                ans += cnt;
            }
            else if(ops[i] == "D"){
                cnt = 2 * score[score.size()-1];
                score.emplace_back(cnt);
                ans += cnt;
            }
            else if(ops[i] == "C"){
                ans -= score[score.size()-1];
                score.pop_back();
            }
            else{
                int num = stoi(ops[i]);
                ans += num;
                score.emplace_back(num);
            }
        }
        return ans;
    }
};
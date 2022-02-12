class Solution {
public:
    bool F(int a, int b){
        for(int i = 2; i <= min(a, b); i++){
            if(a % i == 0 && b % i == 0){
                return false;
            }
        }
        return true;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(F(i, j)){
                    string tmp = "";
                    tmp += to_string(j);
                    tmp += '/';
                    tmp += to_string(i);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};
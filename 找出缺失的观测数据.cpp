class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(int i = 0; i < m; i++){
            sum += rolls[i];
        }
        int left = mean * (n + m) - sum; // n个的sum
        vector<int> ans(n, 0);
        mean = left / n; // n个的mean
        left -= mean * n; // 都用mean表示之后还差多少个没算
        if(mean < 1 || mean > 6 || (mean == 6 && left != 0)){ // 无法表示
            return vector<int>(0, 0);
        }
        else{
            for(int i = 0; i < n; i++){
                if(i < left) // +上用mean表示后没算上的
                    ans[i] = mean + 1;
                else
                    ans[i] = mean;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int code = 0;
        ans.push_back(0);
        ans.push_back(1);
        int length;
        for(int i = 1; i < n; i++){
            // renew code
            length = ans.size() - 1;
            for(int j = length; j >= 0; j--){ // 对称生成
                int tmp = ans[j];
                tmp |= (1 << i);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
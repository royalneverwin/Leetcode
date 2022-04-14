class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int cnt = 0;
        int ans = 1;
        for(int i = 0; i < s.length(); i++){
            if(cnt + widths[s[i] - 'a'] > 100){
                ans++;
                cnt = widths[s[i] - 'a'];
            }
            else
                cnt += widths[s[i] - 'a'];
        }
        vector<int> ret(2, 0);
        ret[0] = ans;
        ret[1] = cnt;
        return ret;
    }
};//
// Created by 王新昊 on 2022/4/12.
//


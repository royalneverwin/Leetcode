//无脑穷举就vans
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0; i < strs[0].length(); i++){
            bool flag = true;
            char tmp = strs[0][i];
            for(int j = 0; j < strs.size(); j++){
                if(strs[j][i] != tmp){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.append(1, tmp);
            }
            else{
                break;
            }
        }
        return ans;
    }
};
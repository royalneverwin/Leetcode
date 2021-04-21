/* 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 */

class Solution {
public:
    bool buddyStrings(string a, string b) {
        if(a.length() != b.length()){//长度不相等，false
            return false;
        }
        /*如果长度相等*/
        char dif[2];
        int ifExist[26];
        memset(ifExist, 0, sizeof(int)*26);
        int difCount = 0;
        for(int i = 0; i < a.length(); i++){
            ifExist[a[i]-'a'] += 1;
            if(a[i] != b[i]){
                if(difCount >= 2){//不同的个数大于2个，不可通过交换得到
                    return false;
                }
                dif[difCount] = i;
                difCount++;
            }
        }
        if(difCount == 0){//判断是否存在重复元素，如果存在重复return true, 否则return false
            for(int i = 0; i < 26; i++){
                if(ifExist[i] > 1){
                    return true;
                }
            }
            return false;
        }
        if(a[dif[0]] == b[dif[1]] && a[dif[1]] == b[dif[0]]){
            return true;
        }
        return false;
    }
};

class Solution {
public:
// 二分搜索
// 利用hash编码将子串转化成数，通过比较数字是否相同来判断子串是否相同
// 因为字符串真的很长，难免会有hash碰撞影响判断，所以设置两个hash编码，两个都对上才算子串相同
// 因为字符串真的很长，所以两个set会超时，把两个hash编码pair成一个变量，然后只用一个set
// 这题 难的批爆 mad 主要是hash编码太难找了
    int Code[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    int ifFind(string& s, int l){ // return index if find, or return -1
        long myMod1 = 1;
        long myMod2 = 1;
        for(int i = 0; i < l-1; i++){
            myMod1 = (myMod1 * 89) % 100037113;
            myMod2 = (myMod2 * 37) % 123477573;
        }
        set<pair<long, long>> hashSet1;
        long strCode1 = 0;
        long strCode2 = 0;
        for(int i = 0; i <= s.length() - l; i++){
            if(strCode1 == 0){
                for(int j = i; j < l + i; j++){
                    strCode1 = (strCode1 * 89 + Code[s[j] - 'a']) % 100037113;
                    strCode2 = (strCode2 * 37 + Code[s[j] - 'a']) % 123477573;
                }
            }
            else{
                strCode1 = ((strCode1 - (Code[s[i-1] - 'a'] * myMod1) % 100037113  + 100037113) % 100037113 * 89 + Code[s[i+l-1] - 'a']) % 100037113;
                strCode2 = ((strCode2 - (Code[s[i-1] - 'a'] * myMod2) % 123477573  + 123477573) % 123477573 * 37 + Code[s[i+l-1] - 'a']) % 123477573;
            }
            if(hashSet1.find(make_pair(strCode1, strCode2)) != hashSet1.end()){
                return i;
            }
            else
                hashSet1.insert(make_pair(strCode1, strCode2));
        }
        return -1;
    }
    string longestDupSubstring(string s) {
        // 最长长度：我们可以用二分查找
        int maxL = s.length() - 1; // 最长重复子串的可能性
        int minL = 0;
        int middleL;
        int tmp;
        int ansIndex;
        int ansL = 0;
        while(maxL != minL){
            if(maxL == minL + 1){
                if((tmp = ifFind(s, maxL)) >= 0){
                    ansIndex = tmp; // 更新ansIndex
                    ansL = maxL; // 更新ansL
                }
                break;
            }
            middleL = (maxL + minL) / 2;
            if((tmp = ifFind(s, middleL)) >= 0){
                ansIndex = tmp; // 更新ansIndex
                minL = middleL;
                ansL = middleL; // 更新ansL
            }
            else{
                maxL = middleL - 1;
            }
        }
        if(ansL == 0)
            return "";
        return s.substr(ansIndex, ansL);
    }
};
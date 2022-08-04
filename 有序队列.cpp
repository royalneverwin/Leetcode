class Solution {
public:
    string orderlyQueue(string s, int k) {
        // 当k = 1: 只能移动第一个字符，循环移动找到字典序最小的
        // 当k > 1: 一定可以移动为字典序最小（这个可以证明）
        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string ans = s;
        for(int i = 1; i < s.length(); i++) {
            s = s.substr(1).append(1, s[0]);
            if(s < ans)
                ans = s;
        }
        return ans;
    }
};
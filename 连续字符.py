class Solution(object):
    def maxPower(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt, ans = 1, 1
        for i in range(1, len(s)): # 不用判断第一个
            if s[i] == s[i-1]:
                cnt += 1;
                ans = max(ans, cnt);
            else:
                cnt = 1;
        return ans;
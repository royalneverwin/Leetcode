class Solution {
public:
    int Subscribe(string& a, string& b){ // a < b
        int mina = a[0] * 10 * 60 + a[1] * 60 + a[3] * 10 + a[4];
        int minb = b[0] * 10 * 60 + b[1] * 60 + b[3] * 10 + b[4];
        int ret = minb - mina;
        if(ret > 720) // 如果大于12h, 则取更短的那一部分作为时间差
            ret = 1440 - ret;
        return ret;

    }
    int findMinDifference(vector<string>& timePoints) {
        int length = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        int ans = 100000000;
        for(int i = 1; i < length; i++){
            ans = min(ans, Subscribe(timePoints[i-1], timePoints[i]));
            if(ans == 0)
                break;
        }
        // 注意最后要比较一下第一个和最后一个的时间差, 形成一个闭环
        ans = min(ans, Subscribe(timePoints[0], timePoints[length-1]));
        return ans;
    }
};
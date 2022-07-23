class Solution {
public:
    static bool Cmp(const vector<int>& a, const vector<int>& b) { // end从小到大排序
        return a[1] < b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Cmp);
        vector<int> ans{intervals[0][1], intervals[0][1]-1};
        int std = intervals[0][1]; // 记录每次应该选择的num
        int sub = 1;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][1] > std) {
                std = intervals[i][1];
                sub = 0;
            }
            int cnt = 0;
            for(auto& n: ans) {
                if(n >= intervals[i][0] && n <= intervals[i][1])
                    cnt++;
                if(cnt == 2)
                    break;
            }
            while(cnt < 2) {
                ans.push_back(std - sub);
                sub++;
                cnt++;
            }
        }

        return ans.size();
    }
};
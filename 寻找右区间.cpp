class Solution {
public:
    class Point{
    public:
        int start;
        int index;
        Point(int s, int i): start(s), index(i) {}
        bool operator < (const Point& other) const {
            return start < other.start;
        }
    };
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<Point> array;
        vector<int> ans(intervals.size(), -1);
        for(int i = 0; i < intervals.size(); i++){
            Point tmp(intervals[i][0], i);
            array.emplace_back(tmp);
        }
        sort(array.begin(), array.end());
        for(int i = 0; i < intervals.size(); i++){
            int end = intervals[array[i].index][1];
            Point tmp(end, 0);
            auto it = lower_bound(array.begin(), array.end(), tmp);
            if(it != array.end()){
                ans[array[i].index] = it->index;
            }

        }
        return ans;
    }
};
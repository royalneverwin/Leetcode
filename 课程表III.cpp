class Solution {
public:
    // 贪心
    // 首先很显然我们可以知道先学lastDay最小的课程
    // 但还要额外考虑：如果遇到一个课程修完会超时，该怎么办？（注意这里一定要考虑！！！）
    // 可以通过反证法证明这时候能修完的课程数不会增加
    // 所以我们只能看看能不能减少修的时间？这样给后面的课程更多时间
    // 需要两个priority_queue
    struct point{
        int dur;
        int last;
        point(int d, int l):dur(d), last(l){}
        bool operator < (const point& other) const{
            return last > other.last;
        }
    };
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<point> lastDay;
        priority_queue<int> duration;
        for(int i = 0; i < courses.size(); i++)
            lastDay.push(point(courses[i][0], courses[i][1]));
        int ans = 0;
        int begin = 0;
        while(!lastDay.empty()){ // find course which has min's lastDay, learn it first
            point tmp = lastDay.top();
            lastDay.pop();
            if(begin + tmp.dur <= tmp.last){ // if can learn, learn it
                begin += tmp.dur;
                ans++;
                duration.push(tmp.dur);
            }
            else if(!duration.empty()){
                int tmp2 = duration.top();
                if(tmp2 > tmp.dur){ // replace courses if possible
                    duration.pop();
                    duration.push(tmp.dur);
                    begin += (tmp.dur - tmp2);
                }
            }
        }
        return ans;
    }
};
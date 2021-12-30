class Solution {
public:
    struct point{
        int index;
        int apple;
        int day;
        point(int i, int a, int d):index(i), apple(a), day(d){}
        bool operator < (const point& other) const{
            return day > other.day;
        }
    };
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = days.size();
        priority_queue<point> pq;
        int cnt[n];
        int ans = 0;
        memset(cnt, 0, sizeof(cnt));
        int i = 0;
        while(i < n || !pq.empty()){
            while(!pq.empty() && pq.top().day == i)
                pq.pop();
            if(i < n && apples[i] != 0)
                pq.push(point(i, apples[i], days[i] + i));
            if(!pq.empty()){
                point tmp = pq.top();
                // cout << tmp.index << ' ' << tmp.apple << ' ' << tmp.day << endl;
                cnt[tmp.index]++;
                ans++;
                if(cnt[tmp.index] == tmp.apple)
                    pq.pop();
            }
            i++;
        }
        return ans;
    }
};
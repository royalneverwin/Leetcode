class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        struct point{
            int i;
            int j;
            int x;
            int y;
            point(int ii, int jj, int xx, int yy): i(ii), j(jj), x(xx), y(yy){}
            bool operator < (const point& other) const{
                return (x / (double)y) < (other.x / (double)other.y);
            }
        };
        vector<point> ans;
        for(int i = 0; i < arr.size() - 1; i++){
            for(int j = i + 1; j < arr.size(); j++){
                ans.push_back(point(i, j, arr[i], arr[j]));
            }
        }
        sort(ans.begin(), ans.end());
        // for(auto i: ans)
        // cout << i.x / (double)i.y << endl;
        vector<int> ret = {ans[k-1].x, ans[k-1].y};
        return ret;
    }
};



class Solution {
public:
    // 优化：优先队列
    // arr[0]/arr[j], arr[1]/arr[j],..., arr[j-1]/arr[j]是一个升序队列
    // 一共有arr.size() - 1个队列
    // 类似“k个升序队列排序”
    // 构造一个优先队列, 队列的top就是最小的.
    // 注意priority_queue是最大的在最上面
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        struct point{
            int i;
            int j; // i, j可以用于像pq中添加新元素
            int x;
            int y;
            point(int ii, int jj, int xx, int yy): i(ii), j(jj), x(xx), y(yy){}
            bool operator < (const point & other) const{
                // x1 / y1 < x2 / y2可以表述为乘积形式！x1 * y2 < x2 * y1;
                return x * other.y > other.x * y; //priority_queue是最大的在最上面
            }
            point(){
                i = j = x = y = 0;
            }
        };
        priority_queue<point> pq;
        for(int i = 1; i < arr.size(); i++){ //push the first of all queue into pq
            pq.push(point(0, i, arr[0], arr[i]));
        }
        int cnt = 0;
        point tmp;
        while(1){
            cnt++;
            tmp = pq.top();
            pq.pop();
            if(cnt == k){
                vector<int> ans = {tmp.x, tmp.y};
                return ans;
            }
            int i = tmp.i;
            int j = tmp.j;
            if(i + 1 < j){
                pq.push(point(i+1, j, arr[i+1], arr[j]));
            }
        }
    }
};
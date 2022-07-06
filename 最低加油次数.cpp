class Solution {
public:
    // “延迟加油” 思想
    // 不要想象加油站 而是随时可以加油
    // 没油的时候就加之前遇到的所有加油站里最多油的加油站
    // 贪心+优先队列
    // 不知道剪枝搜索可不可以 可能会超（x
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int fuel = startFuel;
        int index = 0;
        int ans = 0;
        while(1) {
            if(fuel < target) {
                while(index < stations.size() && stations[index][0] <= fuel) {
                    pq.push(stations[index][1]);
                    index++;
                }
            }
            else {
                break;
            }
            if(pq.empty()) // 无油可加
                return -1;
            fuel += pq.top();
            ans++;
            pq.pop();

        }

        return ans;
    }
};
class Solution {
public:
    int getKthMagicNumber(int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        long res = 1;
        int cnt = 1;
        pq.push(3);
        pq.push(5);
        pq.push(7);
        while(cnt < k) { // 每次将提取出来的3*k, 5*k, 7*k加入到pq中
            res = pq.top();
            while(!pq.empty() && pq.top() == res)
                pq.pop();
            pq.push(3*res);
            pq.push(5*res);
            pq.push(7*res);
            cnt++;
        }
        return res;
    }
};
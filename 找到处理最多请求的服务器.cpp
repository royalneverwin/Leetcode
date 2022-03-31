class Solution {
public:
    typedef pair<int, int> pair;
    struct CMP{
        bool operator ()(const pair& a, const pair& b){
            return a.second > b.second;
        }
    };

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // 一个空闲
        // 一个忙碌
        set<int> free;
        priority_queue<pair, vector<pair>, CMP> pq;
        vector<int> check(k, 0);
        vector<int> ans;
        // 初始化free
        for(int i = 0; i < k; i++)
            free.insert(i);

        for(int i = 0; i < arrival.size(); i++){
            // 每次检验arrival之前把free和busy更新
            while(!pq.empty() && pq.top().second <= arrival[i]){
                free.insert(pq.top().first);
                pq.pop();
            }

            // 如果没有free就扔掉
            if(!free.size()){
                continue;
            }

            auto j = free.lower_bound(i % k); //二分 快很多
            // 没有的话 取最小的
            if(j == free.end())
                j = free.begin();

            pq.push(make_pair(*j, arrival[i] + load[i]));
            check[*j]++;
            free.erase(j);
        }

        int maxCnt = *max_element(check.begin(), check.end());
        for(int i = 0; i < k; i++){
            if(check[i] == maxCnt)
                ans.push_back(i);
        }

        return ans;
    }
};
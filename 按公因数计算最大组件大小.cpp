class Solution {
public:
    // 首先找到nums的最大值
    // 把所有 <= max的正整数利用并查集进行归类
    // 遍历nums 将所有num放到各个类中
    // 找到最大值
    int find(int x, vector<int>& parent) {
        if(parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
    int largestComponentSize(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> parent(maxNum+1, 0);
        vector<int> rank(maxNum+1, 1);
        for(int i = 1; i <= maxNum; i++)
            parent[i] = i;

        int root1, root2;
        for(int num: nums) {
            for(int i = 2; i*i <= num; i++) {
                if(num % i == 0) { // 能被整除 所以把num和i、num和num/i合并
                    // union num i
                    root1 = find(num, parent);
                    root2 = find(i, parent);
                    if(root1 != root2) {
                        if(rank[root1] < rank[root2]) {
                            parent[root1] = root2;
                            rank[root2] += rank[root1];
                        }
                        else {
                            parent[root2] = root1;
                            rank[root1] += rank[root2];
                        }
                    }
                    // union num num/i
                    root1 = find(num, parent);
                    root2 = find(num/i, parent);
                    if(root1 != root2) {
                        if(rank[root1] < rank[root2]) {
                            parent[root1] = root2;
                            rank[root2] += rank[root1];
                        }
                        else {
                            parent[root2] = root1;
                            rank[root1] += rank[root2];
                        }
                    }
                }
            }
        }


        vector<int> cnt(maxNum+1, 0);
        for(int num: nums) {
            cnt[find(num, parent)]++;
        }

        return *max_element(cnt.begin(), cnt.end());
    }
};
class Solution {
public:
    int N;
    // 将后面的映射到前面

    unordered_map<int, int> mmap;
    mt19937 gen{random_device{}()};
    Solution(int n, vector<int>& blacklist) {
        N = n - blacklist.size();
        int index = n-1;
        sort(blacklist.begin(), blacklist.end());

        for(int i = 0; i < blacklist.size(); i++) {
            while(index > blacklist[i] && find(blacklist.begin(), blacklist.end(), index) != blacklist.end())
                index--;

            if(index <= blacklist[i])
                break;
            mmap[blacklist[i]] = index;
            index--;
        }
    }

    int pick() {
        uniform_int_distribution<int> dist(0, N-1);
        int num = dist(gen);
        if(mmap.count(num)) {
            return mmap[num];
        }
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
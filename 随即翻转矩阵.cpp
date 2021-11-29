class Solution {
public:
    // 维护一个map<int, int>, map.firs存放被flip的index, map.second存放如果再被找到该index后, 应该映射到
    // 哪一个新的index中（一般映射到最后一个, 再让total--）
    // 等同于将被flip的index放到所有index的末尾
    // map映射到的新的index一定是没被flip的
    int row;
    int col;
    int total;
    map<int, int> mmap;
    Solution(int m, int n) {
        row = m;
        col = n;
        total = m * n;
    }

    vector<int> flip() {
        int index = rand() % total; // 注意这里不是 % (row & col), 而是 % total
        vector<int> ret;
        total--; // 提前--, 因为index是 < row * col的
        if(mmap.count(index))
            ret = {mmap[index] / col, mmap[index] % col};
        else
            ret = {index / col, index % col};
        if(mmap.count(total)) //total已经被flip
            mmap[index] = mmap[total];
        else
            mmap[index] = total;
        int x = index / col;
        int y = index % col;
        return ret;
    }


    void reset() {
        mmap.clear();
        total = row * col;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
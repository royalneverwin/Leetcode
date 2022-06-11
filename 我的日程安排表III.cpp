class MyCalendarThree {
    map<int, int> mmap;
    int maxH;
public:
    MyCalendarThree() {
        maxH = 0;
        mmap = map<int, int>();
        mmap[0] = 0; // 从0开始h都为0
    }

    int book(int start, int end) {
        auto lt = mmap.lower_bound(start); // >= start

        if(lt == mmap.end() || lt->first > start) {
            lt--;
        }
        // 让lt <= start

        if(lt->first < start) {

            mmap[start] = lt->second + 1;
            cout << start << endl;
            maxH = max(maxH, mmap[start]);
            lt++; // 到了新增的
            lt++; // 再++
        }


        while(lt != mmap.end() && lt->first < end) {
            lt->second++;
            maxH = max(maxH, lt->second);
            lt++;
        }

        if(lt == mmap.end() || lt->first > end) {
            lt--;
            mmap[end] = lt->second - 1;
            // 肯定不是最高的
        }

        return maxH;
    }
};


// 线段树
class MyCalendarThree {

// 用unordered_map是因为不能用数组构造一个真正的树 空间过于浪费 只能用hash表示
// 线段树一般从1开始
    unordered_map<int, pair<int, int>> mmap;

    int maxH;
public:
    MyCalendarThree() {
        mmap = unordered_map<int, pair<int, int>>();
    }

    void Update(int start, int end, int l, int r, int index) {
        if(end < l || r < start)
            return;
        else if(start <= l && r <= end){
            mmap[index].second++;
            mmap[index].first++;
        }
        else {
            int mid = (l + r) >> 1;
            Update(start, end, l, mid, 2 * index);
            Update(start, end, mid + 1, r, 2 * index + 1);
            mmap[index].first = mmap[index].second + max(mmap[2 * index].first, mmap[2 *index + 1].first);
        }
    }

    int book(int start, int end) {
        Update(start, end - 1, 0, 1000000000, 1);
        return mmap[1].first;
    }
};

// 差分数组
class MyCalendarThree {

// 用unordered_map是因为不能用数组构造一个真正的树 空间过于浪费 只能用hash表示
// 线段树一般从1开始
    map<int, int> mmap;

    int maxH;
public:
    MyCalendarThree() {
        mmap = map<int, int>();
    }



    int book(int start, int end) {
        mmap[start]++;
        mmap[end]--;
        int sum = 0;
        int ret = 0;
        for(auto &[_, freq]: mmap) {
            sum += freq;
            ret = max(ret, sum);
        }
        return ret;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
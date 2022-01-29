class StockPrice {
private:
    unordered_map<int, int> mmap; // 哈希表
    multiset<int> ms; // 有序集合
    int curPrice;
    int curTime;
public:
    StockPrice() {
        curPrice = curTime = -1;
    }

    void update(int timestamp, int price) {

        if(mmap.find(timestamp) == mmap.end()){ // 没有覆盖之前的
            ms.insert(price);
            mmap[timestamp] = price;
            if(curTime == -1 || timestamp > curTime){
                curTime = timestamp;
                curPrice = price;
            }
        }
        else{ // 覆盖了之前的
            ms.erase(ms.find(mmap[timestamp]));
            ms.insert(price);
            mmap[timestamp] = price;
            if(timestamp >= curTime){
                curPrice = price;
                curTime = timestamp;
            }
        }
    }

    int current() {
        return curPrice;
    }

    int maximum() {
        auto tmp = ms.end();
        tmp--;
        return *tmp;
    }

    int minimum() {
        auto tmp = ms.begin();
        return *tmp;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
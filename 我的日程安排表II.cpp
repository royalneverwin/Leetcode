class MyCalendarTwo {
public:
    map<int, int> check;
    MyCalendarTwo() {
        check = map<int, int>();
        check[0] = 0;
    }

    bool book(int start, int end) {
        auto lt = check.lower_bound(start);
        if(lt == check.end()) {
            lt--;
            if(lt->second == 2) { // 不insert
                return false;
            }
            check[start] = lt->second + 1;
            check[end] = lt->second;
            return true;
        }
        else if(lt->first == start) {
            // 检查是否需要insert
            auto tmp = lt;
            while(tmp != check.end() && tmp->first < end) {
                if(tmp->second == 2) { // 不insert
                    return false;
                }
                tmp++;
            }
            // 最后insert
            while(lt != tmp) {
                lt->second++;
                lt++;
            }
            if(lt == check.end() || lt->first != end) {
                lt--;
                check[end] = lt->second - 1;
            }
            return true;
        }
        else {
            lt--;
            if(lt->second == 2) { // 不insert
                return false;
            }
            else {
                // 检查是否需要insert
                auto tmp = lt;
                tmp++;
                while(tmp != check.end() && tmp->first < end) {
                    if(tmp->second == 2) { // 不insert
                        return false;
                    }
                    tmp++;
                }
                // 最后insert
                check[start] = lt->second + 1;
                lt++; // 到start
                lt++;
                while(lt != tmp) {
                    lt->second++;
                    lt++;
                }
                if(lt == check.end() || lt->first != end) {
                    lt--;
                    check[end] = lt->second - 1;
                }
                return true;
            }
        }
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
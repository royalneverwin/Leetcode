class RangeModule {
public:
    // 有序集合
    map<int, int> ranges;
    RangeModule() {
        ranges = map<int, int>();
    }

    void ShowRanges() {
        for(auto& i: ranges) {
            cout << i.first << ' ' << i.second << endl;
        }
        cout << endl;
    }
    void addRange(int left, int right) {
        if(ranges.size() == 0) {
            ranges[left] = right;
            return;
        }

        auto lt = ranges.upper_bound(left);
        int newLeft;
        if(lt == ranges.begin()) {
            if(lt->first > right) {
                ranges[left] = right;
                return;
            }
            else {
                newLeft = left;
            }
        }
        else {
            lt--;
            if(lt->first == left) {
                newLeft = left;
            }
            else {
                if(lt->second < left) {
                    newLeft = left;
                    lt++;
                }
                else {
                    newLeft = lt->first;
                }
            }
        }

        auto rt = ranges.upper_bound(right);
        int newRight;
        rt--;
        if(rt->first == right) { // 合并rt
            newRight = rt->second;
            rt++;
        }
        else {
            newRight = max(right, rt->second);
            rt++;
        }

        ranges.erase(lt, rt);
        ranges[newLeft] =  newRight;

    }

    bool queryRange(int left, int right) {

        if(ranges.size() == 0)
            return false;

        auto lt = ranges.upper_bound(left);
        if(lt == ranges.begin())
            return false;

        lt--;
        if(lt->second >= right) {
            return true;
        }
        else {
            return false;
        }
    }

    void removeRange(int left, int right) {

        vector<pair<int, int>> insertList;
        if(ranges.size() == 0) {
            return;
        }

        auto lt = ranges.upper_bound(left);
        if(lt == ranges.begin()) {
            if(lt->first >= right) {
                return;
            }
        }
        else {
            lt--;
            if(lt->second <= left) {
                lt++;
            }
            else {
                insertList.emplace_back(make_pair(lt->first, left)); // 所有修改最后进行
            }
        }

        auto rt = ranges.upper_bound(right);
        rt--;
        if(rt->first < right) {
            if(rt->second <= right) {
                rt++;
            }
            else {
                insertList.emplace_back(make_pair(right, rt->second));
                rt++;
            }
        }

        ranges.erase(lt, rt);
        for(auto &i: insertList) {
            ranges[i.first] = i.second;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
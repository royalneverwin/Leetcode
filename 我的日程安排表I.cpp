class MyCalendar {
public:
    map<int, int> umap;
    MyCalendar() {
        umap = map<int, int>();
    }

    bool book(int start, int end) {
        if(!umap.size()) {
            umap[start] = end;
            return true;
        }
        auto lt = umap.lower_bound(end);
        if(lt == umap.begin()) {
            umap[start] = end;
            return true;
        }

        lt--;
        if(lt->second <= start) {
            umap[start] = end;
            return true;
        }

        return false;


    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
class DetectSquares {
    typedef pair<int, int> pair;
private:
    map<int, set<int>> mapX;    // aim for count, no need for multiset
    multiset<pair> ms;

public:
    DetectSquares() {

    }

    void add(vector<int> point) {
        if(mapX.find(point[0]) == mapX.end()){
            set<int> tmp;
            tmp.insert(point[1]);
            mapX[point[0]] = tmp;
        }
        else{
            mapX[point[0]].insert(point[1]);
        }
        ms.insert(make_pair(point[0], point[1]));
    }

    int count(vector<int> point) {
        if(mapX.find(point[0]) == mapX.end()) // 没有
            return 0;
        else{
            int ret = 0;
            auto i = mapX[point[0]].begin();
            while(i != mapX[point[0]].end()){
                int dis = abs((*i) - point[1]);
                if(dis != 0){

                    ret += ms.count(make_pair(point[0], *i)) *
                           ms.count(make_pair(point[0] - dis, point[1])) *
                           ms.count(make_pair(point[0] - dis, *i));

                    ret += ms.count(make_pair(point[0], *i)) *
                           ms.count(make_pair(point[0] + dis, point[1])) *
                           ms.count(make_pair(point[0] + dis, *i));
                }
                i++;
            }
            return ret;
        }
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
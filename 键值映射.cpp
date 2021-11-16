class MapSum {
public:
    map<string, int> mapSum;
    MapSum() {

    }

    void insert(string key, int val) {
        mapSum[key] = val;
    }

    int sum(string prefix) {
        int sum = 0;
        int length = prefix.length();
        bool flag = true;
        for(auto &i: mapSum){
            flag = true;
            for(int j = 0; j < length; j++){
                if(i.first[j] != prefix[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                sum += i.second;
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
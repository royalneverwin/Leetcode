class AllOne {

    map<int, unordered_set<string>> cntStr;
    unordered_map<string, int> strCnt;

public:
    AllOne() {

    }

    void inc(string key) {
        if(!strCnt.count(key)){ // 没有key 创建一个
            strCnt[key] = 1;
            if(!cntStr.count(1)){ // 没有1
                unordered_set<string> tmp;
                tmp.insert(key);
                cntStr[1] = tmp;
            }
            else{ // 有1
                cntStr[1].insert(key);
            }
        }
        else{ // 有key
            int cnt = strCnt[key];
            strCnt[key]++;
            if(!cntStr.count(cnt+1)){ // 没有cnt+1
                unordered_set<string> tmp;
                tmp.insert(key);
                cntStr[cnt+1] = tmp;
            }
            else{
                cntStr[cnt+1].insert(key);
            }
            cntStr[cnt].erase(key); // remove old one
            if(!cntStr[cnt].size()) // 如果cnt空了 就remove
                cntStr.erase(cnt);
        }
    }

    void dec(string key) {
        int cnt = strCnt[key];
        if(cnt-1 == 0){ // 减为0
            strCnt.erase(key);
            cntStr[cnt].erase(key);
            if(!cntStr[cnt].size())
                cntStr.erase(cnt);
        }
        else{ // 没有减为0
            strCnt[key]--;
            if(!cntStr.count(cnt-1)){
                unordered_set<string> tmp;
                tmp.insert(key);
                cntStr[cnt-1] = tmp;
            }
            else
                cntStr[cnt-1].insert(key);
            cntStr[cnt].erase(key); // remove old one
            if(!cntStr[cnt].size()) // 如果cnt空了 就remove
                cntStr.erase(cnt);
        }
    }

    string getMaxKey() {
        if(!cntStr.size())
            return "";
        auto i = cntStr.end();
        i--;
        return *((i->second).begin());
    }

    string getMinKey() {
        if(!cntStr.size())
            return "";
        auto i = cntStr.begin();
        return *((i->second).begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
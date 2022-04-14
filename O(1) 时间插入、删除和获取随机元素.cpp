class RandomizedSet {
    unordered_map<int, int> umap; // second存放first的在arr的index
    vector<int> arr; // 用来确保getRandom是O（1）的
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if(umap.count(val))
            return false;
        else{
            arr.push_back(val); // arr中加入新元素
            umap[val] = arr.size()-1; // umap中加入新元素
            return true;
        }
    }

    bool remove(int val) {
        if(umap.count(val)){
            umap[arr[arr.size()-1]] = umap[val];// umap中修改arr[arr.size()-1]的index
            arr[umap[val]] = arr[arr.size()-1]; // 修改arr[arr.size()-1]位置
            arr.erase(arr.end()-1); // 删掉元素
            umap.erase(val); // 删掉元素
            return true;
        }
        else
            return false;
    }

    int getRandom() {
        int sum = arr.size();
        int index = rand() % sum;
        return arr[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
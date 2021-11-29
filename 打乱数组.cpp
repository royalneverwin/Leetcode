class Solution {
public:
    vector<int> array;
    vector<int> changeArray;
    Solution(vector<int>& nums) {
        array = nums;
        changeArray = nums;
    }

    vector<int> reset() {
        return array;
    }

    vector<int> shuffle() {
        vector<int> tmp = array;
        for(int i = 0; i < array.size(); i++){
            int index = rand() % tmp.size();
            changeArray[i] = tmp[index];
            tmp.erase(tmp.begin() + index);
        }
        return changeArray;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
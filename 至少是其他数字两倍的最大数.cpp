class Solution {
public:
    typedef pair<int, int> pair;
    class Cmp{
    public:
        bool operator ()(const pair& p1, const pair& p2) const{
            return p1.first > p2.first;
        }
    };
    // 经典寻找第二大算法————大炮打蚊子
    int dominantIndex(vector<int>& nums) {
        int length = nums.size();
        if(length == 1) // 只有一个数 一定是
            return 0;
        map<int, set<pair, Cmp>> greaterOne;
        int maxOne = nums[0];
        int maxIndex = 0;
        for(int i = 1; i < length; i++){
            if(maxOne <= nums[i]){ // 更新maxOne, maxIndex
                if(greaterOne.find(nums[i]) == greaterOne.end()){ // 没有就创建新的
                    set<pair, Cmp> tmp;
                    tmp.insert(make_pair(maxOne, maxIndex));
                    greaterOne[nums[i]] = tmp;
                    maxOne = nums[i];
                    maxIndex = i;
                }
                else{
                    greaterOne[nums[i]].insert(make_pair(maxOne, maxIndex));
                }
            }
            else{
                if(greaterOne.find(maxOne) == greaterOne.end()){ // 没有就创建新的
                    set<pair, Cmp> tmp;
                    tmp.insert(make_pair(nums[i], i));
                    greaterOne[maxOne] = tmp;
                }
                else{
                    greaterOne[maxOne].insert(make_pair(nums[i], i));
                }
            }
        }
        set<pair, Cmp> tmp = greaterOne[maxOne];
        if(maxOne >= (tmp.begin()->first) * 2)
            return maxIndex;
        else{
            return -1;
        }
    }
};



class Solution {
public:
    // 经典寻找第二大算法————炮打蚊子
    int dominantIndex(vector<int>& nums) {
        int length = nums.size();
        if(length == 1) // 只有一个数 一定是
            return 0;
        map<int, set<int, greater<int>>> greaterOne;
        int maxOne = nums[0];
        int maxIndex = 0;
        for(int i = 1; i < length; i++){
            if(maxOne <= nums[i]){ // 更新maxOne, maxIndex
                if(greaterOne.find(nums[i]) == greaterOne.end()){ // 没有就创建新的
                    set<int, greater<int>> tmp;
                    tmp.insert(maxOne);
                    greaterOne[nums[i]] = tmp;
                    maxOne = nums[i];
                    maxIndex = i;
                }
                else{
                    greaterOne[nums[i]].insert(maxOne);
                }
            }
            else{
                if(greaterOne.find(maxOne) == greaterOne.end()){ // 没有就创建新的
                    set<int, greater<int>> tmp;
                    tmp.insert(nums[i]);
                    greaterOne[maxOne] = tmp;
                }
                else{
                    greaterOne[maxOne].insert(nums[i]);
                }
            }
        }
        set<int, greater<int>> tmp = greaterOne[maxOne];
        if(maxOne >= *(tmp.begin()) * 2)
            return maxIndex;
        else{
            return -1;
        }
    }
};


class Solution {
public:
    // 经典寻找第二大算法————超简化
    int dominantIndex(vector<int>& nums) {
        int length = nums.size();
        if(length == 1) // 只有一个数 一定是
            return 0;
        int maxOne = nums[0];
        int maxIndex = 0;
        int maxTwo = -1;
        for(int i = 1; i < length; i++){
            if(maxOne <= nums[i]){ // 更新maxOne, maxIndex
                maxTwo = maxOne;
                maxOne = nums[i];
                maxIndex = i;
            }
            else if(maxTwo < nums[i]){
                maxTwo = nums[i];
            }

        }
        if(maxOne >= maxTwo * 2)
            return maxIndex;
        else{
            return -1;
        }
    }
};
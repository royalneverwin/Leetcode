class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> numFreq;
        unordered_map<int, unordered_set<int>> freqNums;
        int minFreq = 0, maxFreq = 0; // minFreq, maxFreq都不包括1而言
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            numFreq[nums[i]] += 1;
            if (numFreq[nums[i]] == 1) { // 第一次出现
                if (freqNums.count(1)) {
                    freqNums[1].insert(nums[i]);
                }
                else {
                    freqNums[1] = unordered_set<int>();
                    freqNums[1].insert(nums[i]);
                }
            }
            else { // 否则要在freqNums里删掉旧的
                freqNums[numFreq[nums[i]]-1].erase(nums[i]);
                if (freqNums.count(numFreq[nums[i]])) {
                    freqNums[numFreq[nums[i]]].insert(nums[i]);
                }
                else {
                    freqNums[numFreq[nums[i]]] = unordered_set<int>();
                    freqNums[numFreq[nums[i]]].insert(nums[i]);
                }

                if(minFreq == 0 && maxFreq == 0) {
                    minFreq = maxFreq = numFreq[nums[i]];
                }

                if(numFreq[nums[i]] > maxFreq) { // 修改maxFreq
                    maxFreq = numFreq[nums[i]];
                }

                if(numFreq[nums[i]] < minFreq) { // 从1变2了
                    minFreq = numFreq[nums[i]];
                }
                else if(numFreq[nums[i]]-1 == minFreq) { // 可能会修改minFreq
                    if(freqNums[minFreq].size() == 0) {
                        while(minFreq < maxFreq && (!freqNums.count(minFreq) || freqNums[minFreq].size() == 0))
                            minFreq += 1;
                    }
                }
            }
            // 最后判断是否符合删除一个也成立
            if(minFreq == 0 && maxFreq == 0) { // 只有1
                res = i+1;
            }
            else if(numFreq.size() == 1) { // 只有一个元素
                res = i+1;
            }
            else if(minFreq == maxFreq && freqNums[1].size() == 1) { // 其他都一样 只有一个个数为1
                res = i+1;
            }
            else if(minFreq == maxFreq && minFreq == 2 && freqNums[2].size() == 1) { // 其他都一样 只有一个个数为2
                res = i+1;
            }
            else if(minFreq == maxFreq-1 && freqNums[maxFreq].size() == 1 && freqNums[1].size() == 0) { // 其他都一样 只有一个多1
                res = i+1;
            }
        }
        return res;
    }
};
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int length = hand.size();
        if (length % groupSize != 0) // prejudge
            return false;
        map<int, int> mmap;
        for (int i = 0; i < length; i++) { // 构建mmap
            mmap[hand[i]]++;
        }
        // mmap is sorted altomatically
        // 从最小的开始, 每次构建顺子
        auto it = mmap.begin();
        int cnt = 0;
        int tmpCnt = 1;
        int num;
        while (cnt < length) {
            num = it->first;
            it->second--;
            tmpCnt = 1; // 别忘了设初值
            while (tmpCnt < groupSize) {
                num++;
                if (mmap[num] == 0) // 牌不够, false
                    return false;
                else { // 可以构建, 拿走一张牌
                    mmap[num]--;
                    tmpCnt++;
                }
            }
            cnt += tmpCnt;
            while (it != mmap.end() && it->second == 0) {
                it++;
            }
            // if it == mmap.end(), then cnt must == length
        }
        return true;
    }
};


// 快很多, map不用排序, 用unordered
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int length = hand.size();
        if(length % groupSize != 0) // prejudge
            return false;
        unordered_map<int, int> mmap; // 用unordered_map, 会快很多
        for(int i = 0; i < length; i++){ // 构建mmap
            mmap[hand[i]]++;
        }
        sort(hand.begin(), hand.end());
        // 从最小的开始, 每次构建顺子
        int num;
        for(int i = 0; i < length; i++){
            num = hand[i];
            if(mmap[num] == 0) // 这牌已经配对完了
                continue;
            for(int j = 0; j < groupSize; j++){
                if(mmap[num + j] == 0) // 没有这张牌或者牌不够, false
                    return false;
                else
                    mmap[num + j]--;
            }
        }
        return true;
    }
};
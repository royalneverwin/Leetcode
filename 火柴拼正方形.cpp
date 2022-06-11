class Solution {
public:
    bool DFS(vector<int>& matchsticks, int index, int left1, int left2, int left3, int left4) {
        if(index == matchsticks.size()) {
            if(left1 == 0 && left2 == 0 && left3 == 0 && left4 == 0)
                return true;
            else
                return false;
        }

        bool flag = false;
        if(matchsticks[index] <= left1) {
            flag |= DFS(matchsticks, index+1, left1 - matchsticks[index], left2, left3, left4);
        }
        if(matchsticks[index] <= left2) {
            flag |= DFS(matchsticks, index+1, left1, left2 - matchsticks[index], left3, left4);
        }
        if(matchsticks[index] <= left3) {
            flag |= DFS(matchsticks, index+1, left1, left2, left3 - matchsticks[index], left4);
        }
        if(matchsticks[index] <= left4) {
            flag |= DFS(matchsticks, index+1, left1, left2, left3, left4 - matchsticks[index]);
        }

        return flag;
    }


    bool makesquare(vector<int>& matchsticks) {
        int length = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(length % 4 != 0) { // 无法分成四份
            return false;
        }
        length /= 4;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if(matchsticks[0] > length)
            return false;
        return DFS(matchsticks, 1, length - matchsticks[0], length, length, length);
    }
};
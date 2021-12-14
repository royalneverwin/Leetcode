/**
 * 方法：预处理 + 二分搜索
 */
class TopVotedCandidate {
public:
    vector<int> time;
    vector<int> person;
    bool flag;
    vector<int> winner;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        time = times;
        person = persons;
        flag = false;
    }

    int q(int t) {
        if(!flag){
            // pre process
            int tmp[5001];
            memset(tmp, 0, sizeof(tmp));
            int maxCnt = 0;
            int win = 0;
            for(int i = 0; i < time.size(); i++){
                tmp[person[i]]++;
                if(tmp[person[i]] >= maxCnt){
                    maxCnt = tmp[person[i]];
                    win = person[i];
                }
                winner.push_back(win);
            }
            flag = true;
        }
        // we know that winner 递增 and is identical to time
        // binary search
        int left = 0;
        int right = time.size() - 1;
        int middle = 0;
        while(left < right){
            middle = (right + left) / 2;
            if(time[middle] == t)
                break;
            else if(time[middle] > t){
                right = middle - 1;
            }
            else{
                left = middle + 1;
            }
        }
        if(time[middle] == t)
            return winner[middle];
        else if(time[left] > t)
            return winner[left-1];
        else if(time[left] == t)
            return winner[left];
        else
            return winner[left];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
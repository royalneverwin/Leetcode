class RecentCounter {
    queue<int> myq;
public:
    RecentCounter() {
    }

    int ping(int t) {
        myq.push(t);
        while(!myq.empty() && myq.front() < t - 3000)
            myq.pop();


        return myq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */


class RecentCounter {
    vector<int> count;
    int right;
    int left;
public:
    RecentCounter() {
        left = right = 0;
    }

    int ping(int t) {
        count.push_back(t);
        while(left < count.size() && count[left] < t - 3000)
            left++;

        while(right < count.size() && count[right] >= t - 3000)
            right++;

        return right - left;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
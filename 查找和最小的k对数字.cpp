class Solution {
public:
    // 如果ans中已经有了i对, 分别把比这i对大的数对存入堆, 找到最小的
    // <ai + 1, bi>, <ai, bi + 1>
    // 存放的时候注意不要重复存放（要有一个visited）
    // 难点：更好的方法: 先把(a[0], b[0]), (a[1], b[0]), ..., (a[k], b[0])存入堆
    // 这样每次移去(x, y)的时候不需要添加(x + 1, y)了, 因为(x + 1, y)
    // 一定被(x + 1, y - 1)添加过, 就避免了重复存放
    typedef pair<int, int> pair;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int index1 = 0, index2 = 0;
        int length1 = nums1.size(), length2 = nums2.size();
        // lambda表达式
        auto cmp = [&nums1, &nums2](const pair& p1, const pair&p2)->bool{
            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };
        priority_queue<pair, vector<pair>, decltype(cmp)>pq(cmp);
        length1 = min(length1, k);
        for(int i = 0; i < length1; i++){
            pq.push(make_pair(i, 0));
        }
        pair tmp;
        vector<int> point;
        for(int i = 0; i < k; i++){
            if(pq.empty()) // 有可能k比所有数对数都要大！
                break;
            tmp = pq.top();
            pq.pop();
            point = {nums1[tmp.first], nums2[tmp.second]};
            ans.push_back(point);
            if(tmp.second + 1 < length2)
                pq.push(make_pair(tmp.first, tmp.second + 1));
        }
        return ans;

    }
};
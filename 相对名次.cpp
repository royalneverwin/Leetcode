class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score){
        struct point{
            int n;
            int index;
            point(int nn, int i): n(nn), index(i){}
            bool operator < (const point& other) const{
                return n > other.n; //从大到小排序
            }
        };
        int length = score.size();
        vector<point> scores;
        for(int i = 0; i < length; i++){
            scores.push_back(point(score[i], i));
        }
        sort(scores.begin(), scores.end());
        vector<string> ans(length);
        ans[scores[0].index] = "Gold Medal";
        if(length > 1)
            ans[scores[1].index] = "Silver Medal";
        if(length > 2)
            ans[scores[2].index] = "Bronze Medal";
        for(int i = 3; i < length; i++){
            ans[scores[i].index] = to_string(i + 1);
        }
        return ans;
    }
};
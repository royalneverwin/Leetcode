class Solution {
public:
    typedef pair<int, int> pair;

    static bool cmp(vector<int>& v1, vector<int>& v2){
        return v1[0] < v2[0];
    }

    class CmpForPair{
    public:
        bool operator () (const pair& p1, const pair& p2) const{
            return p1.first < p2.first;
        }
    };

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        int ans = 0;
        int length = properties.size();
        int maxDefense[length]; // 比i大的index中最大的maxDefense
        int lastEqualIndex[length]; // 和i的attack相同的最大的index

        // 处理maxDefense和lastEqualIndex
        priority_queue<pair, vector<pair>, CmpForPair> pq;
        int curIndex = 0; // 已经填充的index位置
        pq.push(make_pair(properties[0][1], 0));
        int lastOne = properties[0][0];
        int lastIndex = 0;

        for(int i = 1; i < length; i++){
            if(properties[i][0] != lastOne){
                for(int j = lastIndex; j < i; j++){
                    lastEqualIndex[j] = i - 1;
                }
                lastIndex = i;
                lastOne = properties[i][0];
            }

            pq.push(make_pair(properties[i][1], i));
        }

        for(int i = lastIndex; i < length; i++){
            lastEqualIndex[i] = length - 1;
        }



        while(!pq.empty()){
            pair tmp = pq.top();
            pq.pop();
            if(tmp.second > curIndex){
                while(curIndex < tmp.second){
                    maxDefense[curIndex] = tmp.first;
                    curIndex++;
                }
            }
        }
        maxDefense[length - 1] = -1;


        for(int i = 0; i < length - 1; i++){
            int index = lastEqualIndex[i];
            if(index != length - 1 && maxDefense[index] > properties[i][1])
                ans++;
        }
        return ans;
    }
};



class Solution {
public:
    // 想法 找到比i大的index中最大的maxDefense
    // 实际上不需要maxDefense数组，只需要从后往前找每次更新maxDefense即可！
    // 代码简单许多 但速度没什么区别
    static bool cmp(vector<int>& v1, vector<int>& v2){
        return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] > v2[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp); // 按照attack降序排
        int ans = 0;
        int length = properties.size();
        int maxDefense = 0;
        for(int i = 0; i < length; i++){
            if(properties[i][1] < maxDefense)
                ans++;
            else
                maxDefense = properties[i][1];
        }
        return ans;
    }
};
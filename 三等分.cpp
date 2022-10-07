class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int res1 = -1, res2 = -1;
        int cnt = 0;
        for(auto i: arr) {
            if(i == 1) cnt++;
        }
        if(cnt % 3 != 0) return vector<int>{-1, -1};
        if(cnt == 0) return vector<int>{0, int(arr.size())-1};

        int lastOne = 0;
        int lastZero = 0;
        int idx = arr.size()-1;
        // 构造lastZero
        while(idx >= 0 && arr[idx] != 1) {
            lastZero++;
            idx--;
        }
        // 构造num3
        while(idx >= 0 && lastOne < cnt/3) {
            if(arr[idx] == 1) {
                lastOne++;
            }
            idx--;
        }
        // 找到num2的1的开头
        while(idx >= 0 && arr[idx] != 1) {
            idx--;
        }
        // 找到res2
        for(int i = 1; i <= lastZero; i++) {
            if(arr[idx+i] == 1) return vector<int>{-1, -1};
        }
        res2 = idx + lastZero + 1;
        // 构造num2
        lastOne = 0;
        while(idx >= 0 && lastOne < cnt/3) {
            if(arr[idx] == 1) {
                lastOne++;
            }
            idx--;
        }
        // 找到num2的1的开头
        while(idx >= 0 && arr[idx] != 1) {
            idx--;
        }
        // 找到res1
        for(int i = 1; i <= lastZero; i++) {
            if(arr[idx+i] == 1) return vector<int>{-1, -1};
        }
        res1 = idx + lastZero;
        // 检验三个num是否相同 
        int idx1 = res1, idx2 = res2-1, idx3 = arr.size()-1;
        lastOne = 0;
        while(lastOne < cnt/3) {
            if(arr[idx1] != arr[idx2] || arr[idx2] != arr[idx3]) return vector<int>{-1, -1};
            if(arr[idx1] == 1) lastOne++;
            idx1--;
            idx2--;
            idx3--;
        }
        return vector<int>{res1, res2};
    }
};
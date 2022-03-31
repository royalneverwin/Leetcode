class Solution {
public:
    long long getPalindrome(int index, long long lower, bool flag, long long sum){ // index从1开始
        if(lower == -1 && index < 10){ // 说明length只有一位
            return index;
        }
        else if(lower == -1){
            return -1;
        }
        else if(index > sum){
            return -1;
        }
        if(flag){ // 奇数
            lower += (index - 1) / 10;
        }
        else{ // 偶数
            lower += index - 1;
        }
        string tmp = to_string(lower);
        string reverseOne = tmp;
        reverse(reverseOne.begin(), reverseOne.end());
        if(flag){
            tmp = tmp + to_string((index-1) % 10);
        }
        tmp = tmp + reverseOne;
        return stol(tmp);
    }
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        // 回文数从中间开始增加是递增的
        vector<long long> ans;
        bool flag = intLength % 2; // 0表示偶，1表示奇
        long long lower = intLength == 1 ? -1 : (long long)pow(10, intLength / 2 - 1);
        long long upper = (long long)pow(10, intLength / 2);
        long long sum = flag ? (upper - lower) * 10 : upper - lower;
        for(int i = 0; i < queries.size(); i++){
            long long tmp = getPalindrome(queries[i], lower, flag, sum);
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
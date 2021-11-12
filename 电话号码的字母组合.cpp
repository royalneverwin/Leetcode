//最simple的dfs

class Solution {
public:
    map<int, vector<char>> mmap;
    vector<int> num;
    vector<string> ans;
    void Add(int cnt, string s, int end){
        if(cnt == end){
            ans.push_back(s);
            return;
        }
        string tmp;
        for(int i = 0; i < mmap[num[cnt]].size(); i++){
            tmp = s;
            tmp.append(1, mmap[num[cnt]][i]);
            Add(cnt + 1, tmp, end);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<char> init2 = {'a', 'b', 'c'};
        vector<char> init3 = {'d', 'e', 'f'};
        vector<char> init4 = {'g', 'h', 'i'};
        vector<char> init5 = {'j', 'k', 'l'};
        vector<char> init6 = {'m', 'n', 'o'};
        vector<char> init7 = {'p', 'q', 'r', 's'};
        vector<char> init8 = {'t', 'u', 'v'};
        vector<char> init9 = {'w', 'x', 'y', 'z'};
        mmap[2] = init2;
        mmap[3] = init3;
        mmap[4] = init4;
        mmap[5] = init5;
        mmap[6] = init6;
        mmap[7] = init7;
        mmap[8] = init8;
        mmap[9] = init9;
        if (digits == "")
            return ans;
        for(int i = 0; i < digits.size(); i++){
            num.push_back(digits[i] - '0');
        }
        string ret = "";
        Add(0, ret, num.size());
        return ans;
    }
};
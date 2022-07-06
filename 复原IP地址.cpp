class Solution {
public:
    void DFS(int *nums, int index, int begin, vector<string>& ans, string s) {
        if(index == 4) {
            char ss[16];
            for(int i = 0; i < 4; i++)
                cout << nums[i] << ' ';
            cout << endl;
            sprintf(ss, "%d.%d.%d.%d", nums[0], nums[1], nums[2], nums[3]);
            ans.emplace_back(string(ss));
            return;
        }

        if(begin == s.length())
            return;

        if(index == 3) { // 最后一个
            if(s[begin] == '0' && begin != s.length()-1) { // 错了
                return;
            }

            int num = atoi(s.substr(begin).c_str());
            if(num > 255 || num < 0) {
                return;
            }

            nums[index] = num;
            DFS(nums, index+1, begin, ans, s);
        }

        else {
            if(s[begin] == '0') {
                nums[index] = 0;
                DFS(nums, index+1, begin+1, ans, s);
            }
            else {
                for(int l = 1; l <= min(int(s.length() - begin), 3); l++) {
                    int num = atoi(s.substr(begin, l).c_str());
                    if(num > 255) {
                        continue;
                    }
                    nums[index] = num;
                    DFS(nums, index+1, begin+l, ans, s);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int nums[4];
        vector<string> ans;
        DFS(nums, 0, 0, ans, s);
        return ans;
    }
};
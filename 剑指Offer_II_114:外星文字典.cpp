class Solution {
public:
    string alienOrder(vector<string>& words) {
        // 经典的拓扑排序
        if(words.size() == 1) {
            return words[0];
        }
        vector<vector<int>> bigger(26, vector<int>());
        vector<int> smallerCnt(26, -1);
        string s1, s2;
        int index1, index2;
        for(int i = 0; i < words.size()-1; i++) {
            s1 = words[i];
            s2 = words[i+1];
            int minl = min(s1.length(), s2.length());
            bool flag = false;
            int j;
            for(j = 0; j < minl; j++) {
                if(smallerCnt[s1[j] - 'a'] == -1)
                    smallerCnt[s1[j] - 'a'] = 0;

                if(smallerCnt[s2[j] - 'a'] == -1)
                    smallerCnt[s2[j] - 'a'] = 0;

                if(s1[j] != s2[j]) {
                    bigger[s1[j] - 'a'].emplace_back(s2[j] - 'a');
                    smallerCnt[s2[j] - 'a']++;
                    flag = true;
                    break;
                }
            }

            for(int index1 = j; index1 < s1.length(); index1++) {
                if(smallerCnt[s1[index1] - 'a'] == -1)
                    smallerCnt[s1[index1] - 'a'] = 0;
            }
            for(int index2 = j; index2 < s2.length(); index2++) {
                if(smallerCnt[s2[index2] - 'a'] == -1)
                    smallerCnt[s2[index2] - 'a'] = 0;
            }

            if(!flag) { // 前半部分都相同
                if(s1.length() > s2.length()) { // 不合法
                    cout << "wrong4" << endl;
                    return "";
                }
            }
        }




        string ans;
        while(1) {
            int flag = 0;

            for(int i = 0; i < 26; i++) {
                if(smallerCnt[i] == 0) { // 找到了空的
                    flag = 1;
                    ans.append(1, i + 'a');
                    for(int j = 0; j < bigger[i].size(); j++) {
                        smallerCnt[bigger[i][j]]--;
                    }
                    smallerCnt[i] = -1;

                    break;
                }
                else if(smallerCnt[i] > 0) {
                    flag = 2;
                }
            }


            if(flag == 0) // 都遍历完了
                break;
            else if(flag == 2) { // 又循环
                return "";
            }
        }

        return ans;
    }
};
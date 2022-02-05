class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        int start = 0;
        int end = 0;
        int length1 = s1.length();
        int length2 = s2.length();
        unordered_map<string, int> mmap;
        vector<string> ans;
        bool flag = false;

        // 找到s1中只出现一次的单词
        while(1){
            while(end < length1 && s1[end] != ' '){
                end++;
            }
            if(end == length1)
                flag = true;

            string tmp = s1.substr(start, end - start);

            if(mmap.find(tmp) == mmap.end())
                mmap[tmp] = 1;
            else
                mmap[tmp] = 0;

            if(flag)
                break;
            start = end + 1;
            end = start;

        }

        start = end = 0;
        flag = false;

        // 找到s2中只出现一次的单词
        while(1){
            while(end < length2 && s2[end] != ' '){
                end++;
            }
            if(end == length2)
                flag = true;

            string tmp = s2.substr(start, end - start);

            if(mmap.find(tmp) == mmap.end())
                mmap[tmp] = 1;
            else
                mmap[tmp] = 0;

            if(flag)
                break;
            start = end + 1;
            end = start;
        }

        // 把所有符合要求的单词找出来
        auto i = mmap.begin();
        while(i != mmap.end()){
            if((*i).second == 1)
                ans.push_back((*i).first);
            i++;
        }

        return ans;
    }
};
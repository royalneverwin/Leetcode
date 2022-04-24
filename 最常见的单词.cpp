class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        for(int i = 0; i < banned.size(); i++)
            ban.insert(banned[i]);
        unordered_map<string, int> cnt;
        int begin = 0, end = 0;
        do{
            while(begin < paragraph.length() && !isalpha(paragraph[begin]))
                begin++;
            if(begin == paragraph.length())
                break;
            end = begin;
            while(end < paragraph.length() && isalpha(paragraph[end]))
                end++;
            string tmp = paragraph.substr(begin, end - begin);
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            if(!ban.count(tmp) && !cnt.count(tmp))
                cnt[tmp] = 1;
            else if(!ban.count(tmp))
                cnt[tmp]++;
            begin = end;
        } while(end < paragraph.length());
        if(end > begin){ // 可能begin 比 end 大
            string tmp = paragraph.substr(begin, end - begin);
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            if(!ban.count(tmp) && !cnt.count(tmp))
                cnt[tmp] = 1;
            else if(!ban.count(tmp))
                cnt[tmp]++;
        }
        int maxCnt = 0;
        string ans;
        for(auto& i: cnt){
            cout << i.first << ' ' << i.second << endl;
            if(i.second > maxCnt){
                maxCnt = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};
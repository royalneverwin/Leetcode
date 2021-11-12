//无脑遍历就vans
class Solution {
public:
    int romanToInt(string s) {
        map<string, int> mmap;
        mmap["I"] = 1;
        mmap["IV"] = 4;
        mmap["V"] = 5;
        mmap["IX"] = 9;
        mmap["X"] = 10;
        mmap["XL"] = 40;
        mmap["L"] = 50;
        mmap["XC"] = 90;
        mmap["C"] = 100;
        mmap["CD"] = 400;
        mmap["D"] = 500;
        mmap["CM"] = 900;
        mmap["M"] = 1000;
        int ans = 0;
        int minI;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')){
                string tmp = s.substr(i, 2);
                ans += mmap[tmp];
                i++;
            }
            else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
                string tmp = s.substr(i, 2);
                ans += mmap[tmp];
                i++;
            }
            else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
                string tmp = s.substr(i, 2);
                ans += mmap[tmp];
                i++;
            }
            else{
                string tmp = s.substr(i, 1);
                ans += mmap[tmp];
            }
        }
        return ans;
    }
};
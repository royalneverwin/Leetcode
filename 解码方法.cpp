class Solution {
public:
    // 深搜会TLE
    // 动归
    int numDecodings(string s) {
        vector<int> bp(s.length(), 0);
        if(s[s.length()-1] == '0') // 最后一个不能单独存在
            bp[s.length()-1] = 0;
        else
            bp[s.length()-1] = 1;
        if(s.length() == 1)
            return bp[0];

        if(s[s.length()-2] == '0')
            bp[s.length()-2] = 0;
        else if(s[s.length()-2] == '1')
            bp[s.length()-2] = 1 + bp[s.length()-1];
        else if(s[s.length()-2] == '2' && s[s.length()-1] <= '6')
            bp[s.length()-2] = 1 + bp[s.length()-1];
        else
            bp[s.length()-2] = bp[s.length()-1];

        if(s.length() == 2)
            return bp[0];


        for(int i = s.length()-3; i >= 0; i--){
            if(s[i] == '0')
                bp[i] = 0;
            else if(s[i] == '1')
                bp[i] = bp[i+2] + bp[i+1];
            else if(s[i] == '2' && s[i+1] <= '6')
                bp[i] = bp[i+2] + bp[i+1];
            else
                bp[i] = bp[i+1];
        }

        return bp[0];
    }
};
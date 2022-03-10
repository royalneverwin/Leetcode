class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.length() > b.length())
            return a.length();
        else if(a.length() < b.length())
            return b.length();
        else if(a == b)
            return -1;
        else
            return a.length();
    }
};
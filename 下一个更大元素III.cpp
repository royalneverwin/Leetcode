class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int index = s.length()-1;
        while(index >= 1 && s[index-1] >= s[index])
            index--;
        if(index == 0)
            return -1;
        index--;
        int index2 = -1;
        for(int i = s.length()-1; i > index; i--)
            if(s[i] > s[index] && (index2 == -1 || s[i] < s[index2]))
                index2 = i;
        char c = s[index2];
        s[index2] = s[index];
        s[index] = c;
        sort(s.begin() + index + 1, s.end());
        long ans = 0;
        for(int i = 0; i < s.length(); i++) {
            ans *= 10;
            ans += s[i] - '0';
        }

        if(ans > pow(2, 31)-1)
            return -1;
        else
            return ans;
    }
};
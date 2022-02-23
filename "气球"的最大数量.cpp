class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mmap;
        mmap['b'] = 0;
        mmap['a'] = 0;
        mmap['l'] = 0;
        mmap['o'] = 0;
        mmap['n'] = 0;
        for(int i = 0; i < text.length(); i++){
            mmap[text[i]]++;
        }
        int ans = min(mmap['b'], mmap['a']);
        ans = min(ans, mmap['l'] / 2);
        ans = min(ans, mmap['o'] / 2);
        ans = min(ans, mmap['n']);
        return ans;
    }
};
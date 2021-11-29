class Solution {
public:
    // count number order: z -> 0, w -> 2, u -> 4, x -> 6, g -> 8, 
    // f -> 5, h -> 3,
    // v -> 7, i -> 9,
    // o, n, e -> 1
    string originalDigits(string s) {
        map<char, int> mmap;
        int cnt[10];
        string ans = "";
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < s.length(); i++){
            if(mmap.find(s[i]) == mmap.end())
                mmap[s[i]] = 1;
            else
                mmap[s[i]]++;
        }
        //find 0
        cnt[0] = mmap['z'];
        mmap['o'] -= mmap['z'];
        //find 2
        cnt[2] = mmap['w'];
        mmap['o'] -= mmap['w'];
        //find 4
        cnt[4] = mmap['u'];
        mmap['f'] -= mmap['u'];
        mmap['o'] -= mmap['u'];
        //find 6
        cnt[6] = mmap['x'];
        mmap['i'] -= mmap['x'];
        //find 8
        cnt[8] = mmap['g'];
        mmap['i'] -= mmap['g'];
        mmap['h'] -= mmap['g'];
        //find 5
        cnt[5] = mmap['f'];
        mmap['i'] -= mmap['f'];
        mmap['v'] -= mmap['f'];
        //find 3
        cnt[3] = mmap['h'];
        //find 7
        cnt[7] = mmap['v'];
        //find 9
        cnt[9] = mmap['i'];
        //find 1
        cnt[1] = mmap['o'];
        for(int i = 0; i <= 9; i++){
            ans.append(cnt[i], i + '0');
        }
        return ans;
    }
};
class Solution {
    unordered_map<char, int> mmap;
public:

    bool Cmp(const string & s1, const string& s2){
        for(int i = 0; i < min(s1.length(), s2.length()); i++){
            if(mmap[s1[i]] < mmap[s2[i]])
                return true;
            else if(mmap[s1[i]] > mmap[s2[i]])
                return false;
        }

        if(s1.length() <= s2.length())
            return true;
        else
            return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < 26; i++)
            mmap[order[i]] = i;


        for(int i = 0; i < words.size()-1; i++){
            if(!Cmp(words[i], words[i+1]))
                return false;
        }

        return true;

    }
};
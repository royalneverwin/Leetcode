class MagicDictionary {
public:
    unordered_map<int, vector<string>> mydic;

    MagicDictionary() {
        mydic = unordered_map<int, vector<string>>();
    }

    void buildDict(vector<string> dictionary) {
        for(int i = 0; i < dictionary.size(); i++) {
            int l = dictionary[i].length();
            if(!mydic.count(l)) {
                mydic[l] = vector<string>();
            }
            mydic[l].emplace_back(dictionary[i]);
        }
    }

    bool search(string searchWord) {
        int l = searchWord.size();
        if(!mydic.count(l)) {
            return false;
        }
        for(auto& word: mydic[l]) {
            int cnt = 0;
            for(int j = 0; j < l; j++) {
                if(word[j] != searchWord[j])
                    cnt++;
            }
            if(cnt == 1)
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
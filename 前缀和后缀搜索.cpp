class WordFilter {
public:
    class TrieNode {
    public:
        int maxIndex;
        vector<struct TrieNode *> childs; // 包括'{'
        TrieNode() {
            childs = vector<struct TrieNode *>(27, nullptr);
            maxIndex = -1;
        }

        void Insert(const string& word, int index, int cur) {
            maxIndex = max(index, maxIndex);
            if(cur != word.length()) {
                int k = word[cur] - 'a';
                if(childs[k] == nullptr) {
                    childs[k] = new TrieNode;
                }
                childs[k]->Insert(word, index, cur+1);
            }
        }

        int FindIndex(const string& prefix, int cur) {
            if(cur == prefix.length()) {
                return maxIndex;
            }
            else {
                int k = prefix[cur] - 'a';
                if(childs[k] == nullptr)
                    return -1;
                return childs[k]->FindIndex(prefix, cur+1);
            }
        }
    };

    TrieNode* head;
    unordered_map<string, int> umap;

    WordFilter(vector<string>& words) {
        head = new TrieNode;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j <= words[i].length(); j++) {
                head->Insert(words[i].substr(words[i].length()-j)+"{"+words[i], i, 0);
            }
        }
        umap = unordered_map<string, int>();
    }

    int f(string pref, string suff) {
        if(umap.count(suff+"{"+pref))
            return umap[suff+"{"+pref];
        umap[suff+"{"+pref] = head->FindIndex(suff+"{"+pref, 0);
        return umap[suff+"{"+pref];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */


// hash表
class WordFilter {
public:
    // 把后缀和前缀结合起来

    unordered_map<string, int> umap;
    WordFilter(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            for(int j = 1; j <= words[i].length(); j++) {
                for(int k = 1; k <= words[i].length(); k++) {
                    umap[words[i].substr(words[i].length()-j)+"{"+words[i].substr(0, k)] =
                            max(umap[words[i].substr(words[i].length()-j)+"{"+words[i].substr(0, k)], i);
                }
            }
        }
    }

    int f(string pref, string suff) {
        return umap.count(suff+"{"+pref) == 0?-1:umap[suff+"{"+pref];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
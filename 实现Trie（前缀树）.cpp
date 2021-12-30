class Trie {
public:
    bool isEnd;
    vector<Trie *> trie;

    Trie() {
        trie = vector<Trie *>(26, nullptr);
        isEnd = false;
    }

    void insert(string word) {
        int index;
        Trie *node = this;
        for(int i = 0; i < word.length(); i++){
            index = word[i] - 'a';
            if(node->trie[index] == nullptr){
                node->trie[index] = new Trie();
            }
            node =  node->trie[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        // same as insert
        int index;
        Trie *node = this;
        for(int i = 0; i < word.length(); i++){
            index = word[i] - 'a';
            if(node->trie[index] == nullptr){
                return false;
            }
            node = node->trie[index];
        }
        if(!node->isEnd)
            return false;
        return true;
    }

    bool startsWith(string prefix) {
        // same as search
        int index;
        Trie *node = this;
        for(int i = 0; i < prefix.length(); i++){
            index = prefix[i] - 'a';
            if(node->trie[index] == nullptr){
                return false;
            }
            node = node->trie[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
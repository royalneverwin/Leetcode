class Solution {
public:
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
    };

    bool DFS(vector<bool>& visited, int start, Trie *trie, const string& word){
        int index;
        Trie *node = trie;
        if(start == word.size())
            return true;
        if(visited[start]) // 应该在start = word.size()后面，否则会超范围
            return false;
        visited[start] = true;
        for(int i = start; i < word.size(); i++){
            index = word[i] - 'a';
            if(node->trie[index] == nullptr)
                return false;
            else{
                node = node->trie[index];
                if(node->isEnd){
                    if(DFS(visited, i+1, trie, word))
                        return true;
                }
            }
        }
        return false;
    }
    static bool cmp(string& a, string& b){ // 定义成static
        return a.length() < b.length();
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // 排序肯定是必要的
        // 使用Trie
        // 注意还可以设置一个visited数组, 记忆化DFS, 用于剪枝
        // 如果是连接词, 就放ans里, 不是就放Trie里
        vector<string> ans;
        sort(words.begin(), words.end(), cmp);
        Trie *trie = new Trie;
        for(int i = 0; i < words.size(); i++){
            if(words[i].length() == 0)
                continue;
            vector<bool> visited(words[i].length(), false);
            if(DFS(visited, 0, trie, words[i]))
                ans.push_back(words[i]);
            else
                trie->insert(words[i]);
        }
        return ans;
    }
};
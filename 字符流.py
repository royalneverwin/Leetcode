class StreamChecker:
    # 看题解吧 不知道什么叫AC自动机
    def __init__(self, words: List[str]):
        self.root = Trie()
        for word in words:
            cur = self.root
            for c in word:
                idx = ord(c)-ord('a')
                if cur.children[idx] == None:
                    cur.children[idx] = Trie()
                cur = cur.children[idx]
            cur.end = True # 代表这是一个单词的结尾

        # 构建fail指针
        self.root.fail = self.root # 根节点fail就是根结点
        qu = deque()
        # 这里为什么要用队列，因为没有指向父指针的指针，只能用队列去选择父指针
        # 而且构建fail指针更多的是BFS，宽度优先搜索，所以deque正合适
        for i in range(26):
            if self.root.children[i]:
                qu.append(self.root.children[i])
                self.root.children[i].fail = self.root
            else:
                # 这一步非常关键，如果父节点没有c字符，则需要对父节点的父节点进行查询，用这个就可以
                self.root.children[i] = self.root

        while qu:
            cur = qu.popleft()
            # 这里的作用是使类似'aba'中的ba能匹配上'ba'也能定义为后缀属于字符串数组，而不用重新查询
            cur.end = cur.end or cur.fail.end
            for i in range(26):
                if cur.children[i]:
                    qu.append(cur.children[i])
                    cur.children[i].fail = cur.fail.children[i]
                else:
                    cur.children[i] = cur.fail.children[i]

        self.cur = self.root

    def query(self, letter: str) -> bool:
        self.cur = self.cur.children[ord(letter)-ord('a')]
        return self.cur.end


class Trie:
    def __init__(self):
        self.children = [None for i in range(26)]
        self.end = False
        self.fail = None # fail指针


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
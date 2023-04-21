class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        root = Trie()
        folder.sort()
        res = []
        for f in folder:
            name = f[1:]
            cur = root
            flag = True
            while name != '':
                if '/' in name:
                    idx = name.index('/')
                    first_name = name[:idx]
                    name = name[idx+1:]
                else:
                    first_name = name
                    name = ''
                if first_name not in cur.children:
                    cur.children[first_name] = Trie()
                cur = cur.children[first_name]
                if cur.end == True and name != '':
                    flag = False
                    break
            cur.end = True
            if flag:
                res.append(f)

        return res

class Trie:
    def __init__(self):
        self.children = {}
        self.end = False

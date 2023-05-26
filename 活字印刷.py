class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        my_hash = set()
        n = len(tiles)

        @cache
        def dfs(cur, mask):
            nonlocal n
            nonlocal tiles
            if mask == 0 and cur != '':
                my_hash.add(cur)
            else:
                for i in range(len(tiles)):
                    if (1<<i) & mask: # 还在
                        dfs(cur+tiles[i], mask^(1<<i))
                        dfs(cur, mask^(1<<i))
        dfs('', (1<<n)-1)
        return len(my_hash)
    
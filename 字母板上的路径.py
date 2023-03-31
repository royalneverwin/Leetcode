class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        n = len(target)
        board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]
        qu = []
        idx, res = 0, ''
        while idx < n and target[idx] == 'a':
            idx += 1
            res += '!'
        if idx == n:
            return res
        qu.append((0, 0, idx, res)) # x, y, idx, res
        visited = dict()
        visited[(0, 0)] = idx
        while True:
            x, y, idx, res = qu.pop(0)
            if x == 5:
                new_idx = idx
                new_res = res+'U'
                while board[x-1][y] == target[new_idx]:
                    new_idx += 1
                    new_res += '!'
                    if new_idx == n:
                        return new_res

                if (x-1, y) not in visited or new_idx > visited[(x-1, y)]:
                    visited[(x-1, y)] = new_idx
                    qu.append((x-1, y, new_idx, new_res))
            else:
                if x != 0:
                    new_idx = idx
                    new_res = res+'U'
                    while board[x-1][y] == target[new_idx]:
                        new_idx += 1
                        new_res += '!'
                        if new_idx == n:
                            return new_res

                    if (x-1, y) not in visited or new_idx > visited[(x-1, y)]:
                        visited[(x-1, y)] = new_idx
                        qu.append((x-1, y, new_idx, new_res))
                if x != 4 or (y == 0 and x == 4):
                    new_idx = idx
                    new_res = res+'D'
                    while board[x+1][y] == target[new_idx]:
                        new_idx += 1
                        new_res += '!'
                        if new_idx == n:
                            return new_res

                    if (x+1, y) not in visited or new_idx > visited[(x+1, y)]:
                        visited[(x+1, y)] = new_idx
                        qu.append((x+1, y, new_idx, new_res))
                if y != 0:
                    new_idx = idx
                    new_res = res+'L'
                    while board[x][y-1] == target[new_idx]:
                        new_idx += 1
                        new_res += '!'
                        if new_idx == n:
                            return new_res

                    if (x, y-1) not in visited or new_idx > visited[(x, y-1)]:
                        visited[(x, y-1)] = new_idx
                        qu.append((x, y-1, new_idx, new_res))
                if y != 4:
                    new_idx = idx
                    new_res = res+'R'
                    while board[x][y+1] == target[new_idx]:
                        new_idx += 1
                        new_res += '!'
                        if new_idx == n:
                            return new_res

                    if (x, y+1) not in visited or new_idx > visited[(x, y+1)]:
                        visited[(x, y+1)] = new_idx
                        qu.append((x, y+1, new_idx, new_res))


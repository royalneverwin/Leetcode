class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        locat = [a, b, c]
        locat.sort()
        if locat[1] == locat[0]+1 and locat[2] == locat[1]+1:
            return [0, 0]
        elif locat[1] == locat[0]+1 and locat[2] != locat[1]+1:
            return [1, locat[2]-locat[1]-1]
        elif locat[1] != locat[0]+1 and locat[2] == locat[1]+1:
            return [1, locat[1]-locat[0]-1]
        else:
            if locat[1] == locat[0]+2 or locat[2] == locat[1]+2:
                return [1, locat[2]-locat[0]-2]

            return [2, locat[2]-locat[0]-2]
        
class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        for piece in pieces:
            idx = 0
            for i in range(len(arr)):
                if arr[i] == piece[idx]:
                    while idx < len(piece):
                        if i < len(arr) and arr[i] == piece[idx]:
                            arr[i] = 0
                            i += 1
                            idx += 1
                        else:
                            return False
                    break

            if idx != len(piece):
                return False

        for n in arr:
            if n != 0:
                return False
        return True
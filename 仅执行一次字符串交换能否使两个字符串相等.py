class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        if s1 == s2:
            return True

        idx1, idx2 = -1, -1
        for idx in range(len(s1)):
            if s1[idx] != s2[idx]:
                if idx1 == -1:
                    idx1 = idx
                elif idx2 == -1:
                    idx2 = idx
                    if s1[idx1] != s2[idx2] or s1[idx2] != s2[idx1]:
                        return False
                else:
                    return False

        if idx2 == -1:
            return False
        return True
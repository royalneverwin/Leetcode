class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        n = len(a)

        # a_prefix + b_suffix
        idx1, idx2 = 0, n-1
        while idx1 < idx2:
            if a[idx1] == b[idx2]:
                idx1, idx2 = idx1+1, idx2-1
            else:
                break
        if idx1 >= idx2:
            return True

        # 两种可能 一种a[idx1:idx2+1]回文，一种b[idx1:idx2+1]回文
        i, j = idx1, idx2
        while i < j:
            if a[i] == a[j]:
                i, j = i+1, j-1
            else:
                break
        if i >= j:
            return True
        i, j = idx1, idx2
        while i < j:
            if b[i] == b[j]:
                i, j = i+1, j-1
            else:
                break
        if i >= j:
            return True

        # b_prefix + a_suffix
        idx1, idx2 = n-1, 0
        while idx1 > idx2:
            if a[idx1] == b[idx2]:
                idx1, idx2 = idx1-1, idx2+1
            else:
                break
        if idx1 <= idx2:
            return True

        # 两种可能 一种a[idx1:idx2+1]回文，一种b[idx1:idx2+1]回文
        i, j = idx1, idx2
        while i > j:
            if a[i] == a[j]:
                i, j = i-1, j+1
            else:
                break
        if i <= j:
            return True
        i, j = idx1, idx2
        while i > j:
            if b[i] == b[j]:
                i, j = i-1, j+1
            else:
                break
        if i <= j:
            return True

        return False
class Solution:
    def unique(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return False
        
        assert len(s1) >= len(s2)
        n1, n2 = len(s1), len(s2)
        idx1, idx2 = 0, 0
        while idx2 < n2 and idx1 < n1:
            if s1[idx1] == s2[idx2]:
                idx2 += 1
            
            idx1 += 1
        
        if idx2 == n2:
            return False
        else:
            return True
        
        
    def findLUSlength(self, strs: List[str]) -> int:
        strs.sort(key=lambda x: len(x), reverse=True)
        n = len(strs)
        res = -1
        for i in range(n):
            flag = True
            for j in range(n):
                if j == i:
                    continue
                if len(strs[j]) < len(strs[i]):
                    break
                
                # len(strs[j]) >= len(strs[i])
                if not self.unique(strs[j], strs[i]):
                    flag = False
                    break

            if flag:
                return len(strs[i])
        
        return -1
                
            
            




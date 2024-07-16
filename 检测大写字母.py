class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        n = len(word)
        if len(word) == 1:
            return True

        flag1 = False
        flag2 = True    
        for i in range(n):
            if i != 0 and word[i] >= 'A' and word[i] <= 'Z':
                flag1 = True
            
            if word[i] >= 'a' and word[i] <= 'z':
                flag2 = False
        
        if flag1 == True and flag2 == False:
            return False
        
        return True


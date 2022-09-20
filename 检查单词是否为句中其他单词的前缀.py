class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        ls = sentence.split(' ')
        for i in range(len(ls)):
            for j in range(1, len(ls[i])+1):
                if searchWord == ls[i][0:j]:
                    return i+1
        return -1
class Solution:
    def reorderSpaces(self, text: str) -> str:
        word_list = text.split()
        sum = 0
        for word in word_list:
            sum += len(word)
        blank_len = len(text) - sum
        if len(word_list) == 1: # 特判 只有一个单词的情况
            return word_list[0] + ' ' * (len(text) - len(word_list[0]))
        cur_blank_len = blank_len // (len(word_list)-1)
        left_blank_len = blank_len % (len(word_list)-1)
        return (' ' * cur_blank_len).join(word_list) + ' ' * left_blank_len

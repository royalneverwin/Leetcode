class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        # 朴素方法：找到s中所有子序列存起来
        # 多指针：同时匹配s每个字符和words中每个word的字符 匹配完的word就是子序列
        # 注意这里不能每次都遍历words 会超时
        # 应该每次只遍历开头字母为s[i]的word
        n, res = len(words), 0
        my_dic = defaultdict(list)

        for i, word in enumerate(words):
            my_dic[word[0]].append((i, 0))

        for c in s:
            cur_dic = my_dic[c]
            my_dic[c] = []
            for idx, cnt in cur_dic:
                cnt += 1
                if cnt == len(words[idx]):
                    res += 1
                else:
                    my_dic[words[idx][cnt]].append((idx, cnt))



        return res




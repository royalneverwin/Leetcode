class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        score_dict = {}
        for i in range(26):
            score_dict[chr(ord('a')+i)] = score[i]

        words_score = {} # 每个word对应的score
        words_cnt = {} # 每个word里面有哪些字母
        for word in words:
            scores = 0
            cur_dict = {}
            for w in word:
                scores += score_dict[w]
                if w in cur_dict:
                    cur_dict[w] += 1
                else:
                    cur_dict[w] = 1
            words_cnt[word] = cur_dict
            words_score[word] = scores

        letter_cnt = {} # letter里一共有多少字母
        for l in letters:
            if l in letter_cnt:
                letter_cnt[l] += 1
            else:
                letter_cnt[l] = 1

        n = len(words)
        flag = (1 << n) - 1

        max_score = [0]
        def dfs(flag, cur_score, words_score, words_cnt, letter_cnt, max_score, n):
            if flag == 0:
                max_score[0] = max(max_score[0], cur_score)

            for i in range(n):
                if (1 << i) & flag:
                    can_take = True
                    for key, val in words_cnt[words[i]].items():
                        if key not in letter_cnt or letter_cnt[key] < val:
                            can_take = False
                            break
                    if can_take:
                        for key, val in words_cnt[words[i]].items():
                            letter_cnt[key] -= val
                        dfs(flag ^ (1 << i), cur_score+words_score[words[i]], words_score, words_cnt, letter_cnt, max_score, n)
                        # 回溯
                        for key, val in words_cnt[words[i]].items():
                            letter_cnt[key] += val

            max_score[0] = max(max_score[0], cur_score)

        dfs(flag, 0, words_score, words_cnt, letter_cnt, max_score, n)

        return max_score[0]


class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        # len(sentence1) <= len(sentence2)
        # 注意只可以加一次句子
        sentence1 = sentence1.split()
        sentence2 = sentence2.split()
        if len(sentence1) > len(sentence2):
            tmp = sentence1
            sentence1 = sentence2
            sentence2 = tmp

        n1 = len(sentence1)
        n2 = len(sentence2)

        if sentence2[0] != sentence1[0]: # 开头不同
            flag = True
            for i in range(n1):
                if sentence1[i] != sentence2[n2-n1+i]:
                    flag = False
                    break
            if flag:
                return True
            else:
                return False
        elif sentence2[n2-1] != sentence1[n1-1]: # 结尾不同
            flag = True
            for i in range(n1):
                if sentence1[i] != sentence2[i]:
                    flag = False
                    break
            if flag:
                return True
            else:
                return False
        else: # 中间不同
            idx = 0
            while idx < n1:
                if sentence1[idx] != sentence2[idx]:
                    break
                idx += 1

            for i in range(idx, n1):
                if sentence1[i] != sentence2[n2-n1+i]:
                    return False

            return True




        
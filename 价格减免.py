class Solution:
    def checkNum(self, s: str) -> bool:
        if s == '': # 空
            return False

        for i in s:
            if i < '0' or i > '9':
                return False
        
        return True

    def discountPrices(self, sentence: str, discount: int) -> str:
        # 对于$后面不是有效数字的单词也要及时更新到res里避免下次错误判断
        # 对于开头不是$开头的也不要更新

        res = ''
        while True:
            if sentence == '': # 找完了
                break

            if sentence[0] == '$': # 这个单词可能是价格
                pos = 0
            else: # 这个单词不是价格
                idx = sentence.find(' ')
                if idx == -1: # 没有了
                    res += sentence
                    break
                else:
                    res += sentence[:idx+1]
                    sentence = sentence[idx+1:]
                    continue

            n = len(sentence)

            idx = sentence.find(' ')
            if idx == -1: #最后一个单词
                idx = n
            
            price = sentence[1:idx] # sentence[0] == '$'

            if self.checkNum(price):
                price = float(price)
                price = price * (1 - 0.01 * discount)
                price = "$%.2f" % price
                res += price
                if idx == n:
                    break
                else:
                    res += ' '
                    sentence = sentence[idx+1:]
            
            else:
                res += sentence[:idx+1]
                sentence = sentence[idx+1:]

        
        return res

                

            


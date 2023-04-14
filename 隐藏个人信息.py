class Solution:
    def maskPII(self, s: str) -> str:
        if '@' in s: # 电子邮件
            idx1 = s.index('@')
            new_s = ''

            name = s[:idx1].lower()
            new_s += name[0] + '*****' + name[-1]

            new_s += '@'

            ip = s[idx1+1:].lower()
            new_s += ip

            return new_s
        else: # 电话号码
            new_s = ''
            for c in s:
                if c.isdigit():
                    new_s += c

            local = new_s[len(new_s)-10:]
            nation = new_s[:len(new_s)-10]

            res_s = ''
            if nation != '':
                res_s += '+' + '*'*len(nation) + '-'

            res_s += '***-***-' + local[6:]
            return res_s


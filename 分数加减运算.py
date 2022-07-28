class Solution:
    def Add(self, a, b):
        mole = a[0] * b[1] + a[1] * b[0]
        deno = a[1] * b[1]
        if mole != 0:
            return [mole // gcd(mole, deno), deno // gcd(mole, deno)]
        else:
            return [mole, deno]

    def fractionAddition(self, expression: str) -> str:
        idx = 0
        a = [0, 1]
        while idx < len(expression):
            # 读b
            idx2 = idx
            while expression[idx2] != '/':
                idx2 += 1
            b1 = int(expression[idx:idx2])
            idx = idx2 + 1
            while idx2 < len(expression) and expression[idx2] != '+' and expression[idx2] != '-':
                idx2 += 1
            b2 = int(expression[idx:idx2])
            b = [b1, b2]

            a = self.Add(a, b)
            idx = idx2

        if a[0] == 0:
            return '0/1'
        else:
            return str(a[0]) + '/' + str(a[1])



class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        if expression == 't':
            return True
        elif expression == 'f':
            return False
        elif expression[0] == '!':
            return not self.parseBoolExpr(expression[2:len(expression)-1])
        elif expression[0] == '&':
            idx1, idx2 = 2, 2
            st = 0
            res = True
            while idx2 != len(expression)-1:
                if expression[idx2] == '(':
                    st += 1
                elif expression[idx2] == ')':
                    st -= 1
                elif expression[idx2] == ',' and st == 0:
                    res = res & self.parseBoolExpr(expression[idx1:idx2])
                    idx1 = idx2+1
                idx2 += 1
            res = res & self.parseBoolExpr(expression[idx1:idx2])
            return res

        elif expression[0] == '|':
            idx1, idx2 = 2, 2
            st = 0
            res = False
            while idx2 != len(expression)-1:
                if expression[idx2] == '(':
                    st += 1
                elif expression[idx2] == ')':
                    st -= 1
                elif expression[idx2] == ',' and st == 0:
                    res = res | self.parseBoolExpr(expression[idx1:idx2])
                    idx1 = idx2+1
                idx2 += 1
            res = res | self.parseBoolExpr(expression[idx1:idx2])
            return res
        else:
            print('Wrong Syntax')
            exit(0)
class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8:
            return False

        flag1, flag2, flag3, flag4 = False, False, False, False
        prev = None
        for p in password:
            if p.islower():
                flag1 = True

            if p.isupper():
                flag2 = True

            if p.isdigit():
                flag3 = True

            if p in "!@#$%^&*()-+":
                flag4 = True

            if prev == p:
                return False

            prev = p
        return flag1 and flag2 and flag3 and flag4



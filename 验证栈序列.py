class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        idx1, idx2 = 0, 0
        stack = []
        while idx1 < len(pushed) and idx2 < len(popped):
            if pushed[idx1] == popped[idx2]:
                idx1, idx2 = idx1+1, idx2+1
            else:
                if stack != [] and stack[-1] == popped[idx2]:
                    stack.pop()
                    idx2 = idx2+1
                else:
                    stack.append(pushed[idx1])
                    idx1 += 1

        while idx2 < len(popped):
            if stack[-1] == popped[idx2]:
                idx2 += 1
                stack.pop()
            else:
                return False
        return True


class Solution:
    def minOperations(self, logs: List[str]) -> int:
        layer = 0
        for log in logs:
            if log == '../':
                layer = max(layer-1, 0)
            elif log != './':
                layer += 1

        return layer
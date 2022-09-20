class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        begin = int(len(arr) * 0.05)
        end = len(arr) - begin
        print(arr[begin:end])
        return mean(arr[begin:end])
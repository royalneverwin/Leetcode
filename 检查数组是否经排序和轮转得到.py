class Solution:
    def check(self, nums: List[int]) -> bool:
        flag = False
        tmp = nums[0]
        for i in range(len(nums)-1):
            if flag:
                if nums[i] > tmp:
                    return False

            if nums[i] > nums[i+1]:
                if not flag:
                    flag = True
                else:
                    return False

        if flag and nums[-1] > tmp: # 上面的for测不到nums[-1]
            return False
        return True


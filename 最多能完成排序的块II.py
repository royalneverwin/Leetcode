class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        block_max_lst = []
        cur_max = arr[0]
        idx = 1
        while idx < len(arr):
            if cur_max <= arr[idx]:
                block_max_lst.append(cur_max)
                cur_max = arr[idx]
            else:
                lst_idx = len(block_max_lst)-1
                while lst_idx >= 0:
                    if block_max_lst[lst_idx] <= arr[idx]:
                        break
                    lst_idx -= 1

                if lst_idx == -1:
                    block_max_lst = []
                elif lst_idx < len(block_max_lst)-1:
                    block_max_lst = block_max_lst[0:lst_idx+1]

            idx += 1

        block_max_lst.append(cur_max)

        return len(block_max_lst)



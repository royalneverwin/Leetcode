class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        h_ls = list(enumerate(heights))
        h_ls.sort(key=lambda x: x[1], reverse=True)
        res = []
        for idx, h in h_ls:
            res.append(names[idx])

        return res
            
class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        my_dict = {}
        for val, weight in items1:
            if val not in my_dict:
                my_dict[val] = weight
            else:
                my_dict[val] += weight

        for val, weight in items2:
            if val not in my_dict:
                my_dict[val] = weight
            else:
                my_dict[val] += weight

        res = []
        for k, v in my_dict.items():
            res.append([k, v])
        res.sort(key=lambda x: x[0])

        return res
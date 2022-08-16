class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        my_dic = {}
        for i in range(0, len(groupSizes)):
            if groupSizes[i] not in my_dic:
                my_dic[groupSizes[i]] = [i]
            else:
                my_dic[groupSizes[i]].append(i)

        ret = []
        for key, val in my_dic.items():
            while val!=[]:
                ret.append(val[:key])
                val = val[key:]

        return ret

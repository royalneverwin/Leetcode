class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        my_dic = {}
        for cpdomain in cpdomains:
            idx1 = 0
            while cpdomain[idx1] != ' ':
                idx1 += 1
            cnt = int(cpdomain[0:idx1])

            idx2 = len(cpdomain)-1
            while True:
                while cpdomain[idx2] != ' ' and cpdomain[idx2] != '.':
                    idx2 -= 1
                if cpdomain[idx2+1:] not in my_dic:
                    my_dic[cpdomain[idx2+1:]] = cnt
                else:
                    my_dic[cpdomain[idx2+1:]] += cnt

                if cpdomain[idx2] == ' ':
                    break
                else:
                    idx2 -= 1

        res = []
        for key in my_dic.keys():
            res.append(str(my_dic[key]) + ' ' + key)
        return res




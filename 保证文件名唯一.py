class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        my_hash = {}
        res = []
        for name in names:
            if name in my_hash:
                while True:
                    new_name = name+'('+str(my_hash[name])+')'
                    my_hash[name] += 1
                    if new_name not in my_hash:
                        break
                my_hash[new_name] = 1
                res.append(new_name)
            else:
                my_hash[name] = 1
                res.append(name)

        return res

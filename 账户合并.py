class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        res = defaultdict(set)
        name_cnt = {}
        mail_dict = {}
        for vals in accounts:
            flag = True
            old_mail_list = []
            key = vals[0]
            val = vals[1:]
            for mail in val:
                if mail in mail_dict: # 老人
                    flag = False
                    old_mail_list.append(mail)
    
            if flag: # 新人
                if key not in name_cnt: # 没有重名
                    name_cnt[key] = 1
                    new_key = key
                else:
                    new_key = key + str(name_cnt[key])
                    name_cnt[key] += 1
                
                for mail in val:
                    res[new_key].add(mail)
                    mail_dict[mail] = new_key
            else: # 老人
                name_set = set()
                for old_mail in old_mail_list:
                    name_set.add(mail_dict[old_mail])
                name_set = list(name_set)
                if len(name_set) > 1: # 合并
                    for i in range(1, len(name_set)):
                        for mail in res[name_set[i]]:
                            res[name_set[0]].add(mail)
                            mail_dict[mail] = name_set[0]
                        del res[name_set[i]]

                for mail in val:
                    res[name_set[0]].add(mail)
                    mail_dict[mail] = name_set[0]

        ans = [] 
        for key, val in res.items(): # 处理成答案需要的格式
            flag = True
            for i in range(len(key)):
                if key[i] >= '0' and key[i] <= '9':
                    flag = False
                    break
            if not flag:
                new_key = key[:i]
            else:
                new_key = key
            cur_ans = [new_key]
            mails = list(val)
            mails.sort()
            for mail in mails:
                cur_ans.append(mail)
        
            ans.append(cur_ans)

        return ans
            


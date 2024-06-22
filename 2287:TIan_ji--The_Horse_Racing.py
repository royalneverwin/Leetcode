# 如果无脑比较田忌最差的是否比得过国王最差的，会在二者战力相等的时候出现困境：比还是不比？
# e.g. 田忌: 2 4, 国王: 2, 3, 这个时候应该比，因为田忌的4大于国王的3
# e.g. 田忌：2 4, 国王: 2, 5, 这个时候不应该比，因为田忌的4小于国王的3
# 并且你会发现, 如果我们各自增加一个马, 变成 田忌: 2 x1 4, 国王: 2, x2, 5, 会发现无论x1 x2的大小是什么, 拿2比5都是最好的方案之一
# 并且你会发现, 如果我们各自增加一个马, 变成 田忌: 2 x1 5, 国王: 2, x2, 4, 会发现无论x1 x2之间的大小如何, 拿5比4都是最好的方案之一
# 且你会发现, 如果我们各自增加一个马, 变成 田忌: 2 x1 4, 国王: 2 x2 4, 会发现无论x1 x2的大小是什么, 拿2比4都是最好的方案之一
# 综上 此时的判断应该与田忌和国王最好的马有关
# 这就需要涉及到田忌和国王最好的马的记录
# 代码主体以此为依据进行调整
# 样例如下：
# 4
# 5 5 3 2
# 5 5 4 2
# 2
# 2 4
# 2 3
# 0

def main():
    while True:
        n = int(input())
        if n == 0:
            break
        a_list = sorted(list(map(int, input().split())))
        b_list = sorted(list(map(int, input().split())))
        win_cnt = 0
        lose_cnt = 0
        a_begin = 0
        b_begin = 0
        a_last_idx = n-1
        b_last_idx = n-1
        while a_begin < a_last_idx and b_begin < b_last_idx:
            
            # obvious
            while a_list[a_begin] > b_list[b_begin] and a_begin < a_last_idx and b_begin < b_last_idx:
                win_cnt += 1
                a_begin += 1
                b_begin += 1
            if a_begin == a_last_idx or b_begin == b_last_idx:
                break
                
            # obvious
            while a_list[a_last_idx] > b_list[b_last_idx] and a_begin < a_last_idx and b_begin < b_last_idx:
                win_cnt += 1
                a_last_idx -= 1
                b_last_idx -= 1
            if a_begin == a_last_idx or b_begin == b_last_idx:
                break
            
            # obvious
            if a_list[a_begin] < b_list[b_begin]:
                lose_cnt += 1
                a_begin += 1
                b_last_idx -= 1
                
            # 见上面分析 注意此时一定有a_list[a_last_idx] <= b_list[b_last_idx]
            elif a_list[a_begin] == b_list[b_begin]:
                if a_list[a_begin] < b_list[b_last_idx]:
                    lose_cnt += 1
                a_begin += 1
                b_last_idx -= 1
         
        
        # last one
        if a_list[a_begin] > b_list[b_begin]:
            win_cnt += 1
        elif a_list[a_begin] < b_list[b_begin]:
            lose_cnt += 1
            
        ans = 200 * (win_cnt - lose_cnt)
        print(ans)
    return


main()

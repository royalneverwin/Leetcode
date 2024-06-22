def main():
    t = int(input())
    inf = 999999999
    for _ in range(t):
        n, x, y, max_h = list(map(int, input().split()))
        l = []
        for __ in range(n):
            l.append(list(map(int, input().split())))
        l = sorted(l, key=lambda x: x[2])  # 将平台按高度排序，使用dp，从最低的平台开始解决问题
        l.insert(0, [-30000, 30000, 0])  # 将地面视为一个平台
        l_dp = [0] * (n + 1)  # 从第i个平台左端下落需要的最短时间
        r_dp = [0] * (n + 1)  # 从第i个平台右端下落需要的最短时间
        for i in range(1, n + 1):
            h_i = l[i][2]
            # 向左跑
            for j in reversed(range(i)):
                dh = h_i - l[j][2]
                if l[j][0] <= l[i][0] <= l[j][1]:  # 找到落到哪个平台上（一定有，因为将地面也视为一个平台）
                    if dh <= max_h:  # 没有摔死
                        if j != 0:  # 不是地面
                            l_dp[i] = dh + min(l_dp[j] + l[i][0] - l[j][0], r_dp[j] + l[j][1] - l[i][0])
                        else:  # 是地面
                            l_dp[i] = dh
                    else:
                        l_dp[i] = inf  # 若摔死用inf表示不可达
                    break
            # 向右跑
            for j in reversed(range(i)):
                dh = h_i - l[j][2]
                if l[j][0] <= l[i][1] <= l[j][1]:
                    if dh <= max_h:
                        if j != 0:
                            r_dp[i] = dh + min(l_dp[j] + l[i][1] - l[j][0], r_dp[j] + l[j][1] - l[i][1])
                        else:
                            r_dp[i] = dh
                    else:
                        r_dp[i] = inf
                    break
        for i in reversed(range(n + 1)):  # 找到落到的第一个平台
            if l[i][0] <= x <= l[i][1]:
                first_stage = i
                break
        if first_stage != 0:
            ans = y - l[first_stage][2] + min(x - l[first_stage][0] + l_dp[first_stage], l[first_stage][1] - x + r_dp[first_stage])
        else:
            ans = y
        print(ans)
    return


if __name__ == '__main__':
    main()

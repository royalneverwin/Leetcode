import copy
from queue import Queue  #优先级队列，优先级高的先输出
        
        
def recur(x1, y1, x2, y2, l, n):
    q = Queue()

    # start or end cannot be reached
    if l[x1][y1] == '#' or l[x2][y2] == '#':
        return 'NO'

    # start == end
    if x1 == x2 and y1 == y2:
        return 'YES'

    # build visit list
    visited_list = [[0 if l[i][j]=='.' else 1 for j in range(n)] for i in range(n)]
    
    q.put((x1, y1))
    visited_list[x1][y1] = 1
    
    while not q.empty():
        cur_x1, cur_y1 = q.get()

        nxt_move_list = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        for dx, dy in nxt_move_list:
            nxt_x1 = cur_x1 + dx
            nxt_y1 = cur_y1 + dy
            # take nxt_x1, nxt_y1 into account
            if nxt_x1 <= n-1 and nxt_x1 >= 0 and nxt_y1 <= n-1 and nxt_y1 >= 0 and visited_list[nxt_x1][nxt_y1] == 0:
                if nxt_x1 == x2 and nxt_y1 == y2:
                    return 'YES'
                q.put((nxt_x1, nxt_y1))
                visited_list[nxt_x1][nxt_y1] = 1
                
    return 'NO'


def main():
    k = int(input())
    for _ in range(k):
        n = int(input())
        l = []
        for __ in range(n):
            l.append(list(input()))
            
        start_i, start_j, end_i, end_j = list(map(int, input().split()))
            
        print(recur(start_i, start_j, end_i, end_j, l, n))
        
    return


if __name__ == '__main__':
    main()
    

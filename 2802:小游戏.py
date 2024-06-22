import copy
from queue import PriorityQueue  #优先级队列，优先级高的先输出


my_hash = lambda x1, y1, x2, y2: x1 + 80*y1 + 6400*x2 + 512000*y2


class Solution:
    def __init__(self, board_list, w, h):
        self.board_list = board_list
        self.visited_list = []
        self.w = w
        self.h = h
        self.q = PriorityQueue()
        

        
    def recur(self,x1, y1, x2, y2):
        if x1 == x2 and y1 == y2:
            print(x1, y1, x2, y2, 0)
            return 0
        
        # build visit list
        self.visited_list = copy.deepcopy(self.board_list)
        self.visited_list[y2][x2] = 0
        # clean q
        while not self.q.empty():
            self.q.get()
        
        self.q.put((0, (x1, y1, 'None')))
        while not self.q.empty():
            cnt, src = self.q.get()
            cur_x1, cur_y1, cur_direc = src
            if cur_x1 == x2 and cur_y1 == y2:
                return cnt

            ans = 10000
            move = []
            nxt_move_list = [(1, 0, 'R'), (0, 1, 'D'), (-1, 0, 'L'), (0, -1, 'U')]
            for dx, dy, nxt_direc in nxt_move_list:
                nxt_x1 = cur_x1 + dx
                nxt_y1 = cur_y1 + dy
                # take nxt_x1, nxt_y1 into account
                if nxt_x1 <= self.w+1 and nxt_x1 >= 0 \
                    and nxt_y1 <= self.h+1 and nxt_y1 >= 0:
                    if cur_direc == nxt_direc:
                        cur_cnt = cnt
                    else:
                        cur_cnt = cnt+1
                    if self.visited_list[nxt_y1][nxt_x1] == 0 or \
                        self.visited_list[nxt_y1][nxt_x1] > cur_cnt:
                        
                        self.visited_list[nxt_y1][nxt_x1] = cur_cnt
                        self.q.put((cur_cnt, (nxt_x1, nxt_y1, nxt_direc)))

        return -1


def main():
    board_cnt = 1
    while True:
        w, h=list(map(int,input().split()))
        if w == 0 and h == 0:
            break
        print(f'Board #{board_cnt}:')
        board_cnt += 1
        board_list = [[0 for j in range(w + 10)] for i in range(h + 10)]
        for i in range(h):
            s = list(input())
            for j in range(w):
                if s[j] =='X':
                    board_list[i + 1][j + 1] = 1
        pair_cnt = 1
        sol = Solution(board_list, w, h)

        
        while True:
            x1, y1, x2, y2 = list(map(int,input().split()))
            if x1 == 0 and y1 == 0 and x2 == 0 and y2 == 0:
                break
            ans = sol.recur(x1, y1, x2, y2)
            # add this to avoid board_list[y1][x1] = 0 and  board_list[y2][x2] = 0
            if ans == -1:
                print(f'Pair {pair_cnt}: impossible.')
            else:
                print(f'Pair {pair_cnt}: {ans} segments.')
            pair_cnt += 1
        
        print()
    return


if __name__ == '__main__':
    main()
    
